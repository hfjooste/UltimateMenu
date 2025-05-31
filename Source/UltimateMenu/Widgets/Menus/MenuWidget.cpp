#include "MenuWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/OverlaySlot.h"
#include "Kismet/GameplayStatics.h"
#include "UltimateMenu/Core/MenuManager.h"
#include "UltimateMenu/Settings/UltimateMenuMenuAppearance.h"
#include "UltimateMenu/Utils/UltimateMenuUtils.h"
#include "UltimateMenu/Widgets/Backgrounds/MenuBackgroundWidget.h"
#include "UltimateMenu/Widgets/Elements/UltimateMenuButton.h"
#include "UltimateMenu/Widgets/Base/FocusableWidget.h"
#include "UltimateMenu/Widgets/Elements/UltimateMenuImage.h"
#include "UltimateMenu/Widgets/Elements/UltimateMenuText.h"

void UMenuWidget::LoadMenu(AMenuManager* Manager, UUltimateMenuMenuAppearance* Appearance,
	const FUltimateMenuMenuConfigData& NewMenuConfig)
{
	if (!IsValid(Manager) || !IsValid(Appearance))
	{
		return;
	}
	
	MenuManager = Manager;
	MenuAppearance = Appearance;
	MenuConfig = NewMenuConfig;

	MenuBehaviour = !IsValid(Appearance) || MenuConfig.bOverrideBehaviour
		? MenuConfig.Behaviour
		: Appearance->Behaviour;

	RefreshScreenPosition(Appearance);
	RefreshMenuPosition(Appearance);
	UUltimateMenuUtils::ApplySizeBoxConfig(SizeBox, Appearance->MenuSize);
	
	Content->ClearChildren();
	Items.Empty();
	
	for (FUltimateMenuMenuItemConfig ItemConfig : MenuConfig.Items)
	{
		switch (ItemConfig.ElementType)
		{
		case EUltimateMenuElementType::Custom:
			break;
		case EUltimateMenuElementType::Button:
			CreateButton(ItemConfig);
			break;
		case EUltimateMenuElementType::Image:
			CreateImage(ItemConfig);
			break;
		case EUltimateMenuElementType::Text:
			CreateText(ItemConfig);
			break;
		}
	}

	if (!Items.IsEmpty())
	{
		Items[0]->ForceFocus();
	}

	if (IsValid(Appearance) && IsValid(Appearance->BackgroundWidgetClass))
	{
		UMenuBackgroundWidget* Background = CreateWidget<UMenuBackgroundWidget>(
			GetWorld(), Appearance->BackgroundWidgetClass);
		BackgroundOverlay->InsertChildAt(0, Background);
		Background->ApplyConfig(Appearance->BackgroundConfig); 
	}
}

void UMenuWidget::SetAsActive()
{
	EnableInput();
	
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	AboveScreenBlur->SetVisibility(ESlateVisibility::Collapsed);
	AboveScreenBlur->SetBlurStrength(0.0f);
	MenuBlur->SetVisibility(ESlateVisibility::Collapsed);
	MenuBlur->SetBlurStrength(0.0f);

	if (MenuBehaviour.Active.bBlurScreenWhenActive)
	{
		BelowScreenBlur->SetVisibility(ESlateVisibility::Visible);
		BelowScreenBlur->SetBlurStrength(MenuBehaviour.Active.BlurScreenStrength);
	}

	if (IsValid(MenuAppearance) && MenuBehaviour.Active.bPauseWhenActive)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}

void UMenuWidget::SetAsInactive()
{
	if (!IsValid(MenuAppearance) || MenuBehaviour.Inactive.bAlwaysActive)
	{
		return;
	}
	
	DisableInput();
	BelowScreenBlur->SetVisibility(ESlateVisibility::Collapsed);
	BelowScreenBlur->SetBlurStrength(0.0f);
	
	if (MenuBehaviour.Inactive.bUnpauseWhenInactive)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
	}
	
	if (MenuBehaviour.Inactive.bHideWhenInactive)
	{
		SetVisibility(ESlateVisibility::Collapsed);
	}

	if (MenuBehaviour.Inactive.bBlurScreenWhenInactive)
	{
		AboveScreenBlur->SetVisibility(ESlateVisibility::Visible);
		AboveScreenBlur->SetBlurStrength(MenuBehaviour.Inactive.BlurScreenStrength);
	}

	if (MenuBehaviour.Inactive.bBlurMenuWhenInactive)
	{
		MenuBlur->SetVisibility(ESlateVisibility::Visible);
		MenuBlur->SetBlurStrength(MenuBehaviour.Inactive.BlurMenuStrength);
	}
}

void UMenuWidget::RemoveFromParent()
{
	Super::RemoveFromParent();
	if (IsValid(MenuAppearance) && MenuBehaviour.Removed.bUnpauseWhenRemoved)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
	}
}

void UMenuWidget::NavigateUp()
{
	Super::NavigateUp();
	if (NavigationDirection == EUltimateMenuMenuNavigationDirection::Vertical)
	{
		FocusPreviousItem();
	}
}

void UMenuWidget::NavigateDown()
{
	Super::NavigateDown();
	if (NavigationDirection == EUltimateMenuMenuNavigationDirection::Vertical)
	{
		FocusNextItem();
	}
}

void UMenuWidget::NavigateLeft()
{
	Super::NavigateLeft();
	if (NavigationDirection == EUltimateMenuMenuNavigationDirection::Horizontal)
	{
		FocusPreviousItem();
	}
}

void UMenuWidget::NavigateRight()
{
	Super::NavigateRight();
	if (NavigationDirection == EUltimateMenuMenuNavigationDirection::Horizontal)
	{
		FocusNextItem();
	}
}

void UMenuWidget::TabLeft()
{
	Super::TabLeft();
	if (NavigationDirection == EUltimateMenuMenuNavigationDirection::Tab)
	{
		FocusPreviousItem();
	}
}

void UMenuWidget::TabRight()
{
	Super::TabRight();
	if (NavigationDirection == EUltimateMenuMenuNavigationDirection::Tab)
	{
		FocusNextItem();
	}
}

void UMenuWidget::Select()
{
	Super::Select();
	if (!Items.IsEmpty())
	{
		Items[SelectedIndex]->ForceSelect();
	}
}

void UMenuWidget::Back()
{
	Super::Back();
	switch (MenuConfig.BackCallbackType)
	{
	case EUltimateMenuMenuItemCallbackType::None:
		break;
	case EUltimateMenuMenuItemCallbackType::PopMenu:
		MenuManager->PopMenu();
		break;
	case EUltimateMenuMenuItemCallbackType::PushMenu:
		MenuManager->PushMenu(MenuConfig.BackMenuName);
		break;
	case EUltimateMenuMenuItemCallbackType::LoadLevel:
		UGameplayStatics::OpenLevel(GetWorld(), MenuConfig.BackLevelName);
		break;
	case EUltimateMenuMenuItemCallbackType::QuitGame:
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0),
			EQuitPreference::Quit, false);
		break;
	case EUltimateMenuMenuItemCallbackType::Custom:
		MenuManager->BackNavigationPerformed(MenuConfig.BackCallbackId);
		break;
	}
}

void UMenuWidget::RefreshScreenPosition(const UUltimateMenuMenuAppearance* Appearance) const
{
	if (!IsValid(Appearance))
	{
		return;
	}
	
	UOverlaySlot* OverlaySlot = UWidgetLayoutLibrary::SlotAsOverlaySlot(SizeBox);
	if (!IsValid(OverlaySlot))
	{
		return;
	}

	OverlaySlot->SetHorizontalAlignment(Appearance->ScreenHorizontalAlignment);
	OverlaySlot->SetVerticalAlignment(Appearance->ScreenVerticalAlignment);
	OverlaySlot->SetPadding(Appearance->ScreenPadding);
}

void UMenuWidget::RefreshMenuPosition(const UUltimateMenuMenuAppearance* Appearance) const
{
	if (!IsValid(Appearance))
	{
		return;
	}
	
	UOverlaySlot* OverlaySlot = UWidgetLayoutLibrary::SlotAsOverlaySlot(Content);
	if (!IsValid(OverlaySlot))
	{
		return;
	}

	OverlaySlot->SetHorizontalAlignment(Appearance->MenuHorizontalAlignment);
	OverlaySlot->SetVerticalAlignment(Appearance->MenuVerticalAlignment);
	OverlaySlot->SetPadding(Appearance->MenuPadding);
}

void UMenuWidget::FocusNextItem()
{
	if (!Items.IsEmpty())
	{
		Items[FMath::Min(SelectedIndex + 1, Items.Num() - 1)]->ForceFocus();
	}
}

void UMenuWidget::FocusPreviousItem()
{
	if (!Items.IsEmpty())
	{
		Items[FMath::Max(SelectedIndex - 1, 0)]->ForceFocus();
	}
}

void UMenuWidget::CreateButton(const FUltimateMenuMenuItemConfig& ItemConfig)
{
	UUltimateMenuButton* Button = CreateWidget<UUltimateMenuButton>(GetWorld(), ItemConfig.WidgetClass);
	if (!IsValid(Button))
	{
		return;	
	}

	Items.Add(Button);
	Content->AddChild(Button);

	Button->InitializeButton(MenuManager, MenuConfig.MenuType, ItemConfig);
	Button->OnFocused.AddDynamic(this, &UMenuWidget::ItemFocused);
	Button->OnSelected.AddDynamic(this, &UMenuWidget::ItemSelected);
}

void UMenuWidget::CreateImage(const FUltimateMenuMenuItemConfig& ItemConfig) const
{
	UUltimateMenuImage* ImageWidget = CreateWidget<UUltimateMenuImage>(GetWorld(), ItemConfig.WidgetClass);
	if (!IsValid(ImageWidget))
	{
		return;	
	}

	Content->AddChild(ImageWidget);
	ImageWidget->InitializeImage(ItemConfig.ImageAppearance);
}

void UMenuWidget::CreateText(const FUltimateMenuMenuItemConfig& ItemConfig) const
{
	UUltimateMenuText* TextWidget = CreateWidget<UUltimateMenuText>(GetWorld(), ItemConfig.WidgetClass);
	if (!IsValid(TextWidget))
	{
		return;	
	}

	Content->AddChild(TextWidget);
	TextWidget->InitializeText(MenuManager, ItemConfig.Text, ItemConfig.TextAppearance);
}

void UMenuWidget::ItemFocused(UWidget* Item)
{
	if (Items.IsEmpty())
	{
		return;
	}
	
	const int NewIndex = Items.IndexOfByKey(Item);
	if (NewIndex == INDEX_NONE || NewIndex == SelectedIndex)
	{
		return;
	}
	
	Items[SelectedIndex]->ForceUnfocus();
	SelectedIndex = NewIndex;
}

void UMenuWidget::ItemSelected(const FUltimateMenuMenuItemConfig& Config)
{
	switch (Config.CallbackType)
	{
	case EUltimateMenuMenuItemCallbackType::None:
		break;
	case EUltimateMenuMenuItemCallbackType::PopMenu:
		MenuManager->PopMenu();
		break;
	case EUltimateMenuMenuItemCallbackType::PushMenu:
		MenuManager->PushMenu(Config.MenuName);
		break;
	case EUltimateMenuMenuItemCallbackType::LoadLevel:
		UGameplayStatics::OpenLevel(GetWorld(), Config.LevelName);
		break;
	case EUltimateMenuMenuItemCallbackType::QuitGame:
		UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0),
			EQuitPreference::Quit, false);
		break;
	case EUltimateMenuMenuItemCallbackType::Custom:
		MenuManager->ItemSelected(Config.CallbackId);
		break;
	}
}
