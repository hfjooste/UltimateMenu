#include "MenuManager.h"

#include "UltimateMenu/Settings/UltimateMenuMenuAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuMenuConfig.h"
#include "UltimateMenu/Settings/UltimateMenuSettings.h"
#include "UltimateMenu/Settings/UltimateMenuTheme.h"
#include "UltimateMenu/Utils/UltimateMenuUtils.h"
#include "UltimateMenu/Widgets/Menus/MenuWidget.h"

void AMenuManager::BeginPlay()
{
	Super::BeginPlay();
	const UUltimateMenuSettings* Settings = GetDefault<UUltimateMenuSettings>();
	Theme = IsValid(Settings) ? Settings->Theme.LoadSynchronous() : nullptr;
	MenuConfig = IsValid(Settings) ? Settings->Menus.LoadSynchronous() : nullptr;
	
	if (InitialMenuName != NAME_None)
	{
		PushMenu(InitialMenuName);
	}
}

void AMenuManager::PushMenu(const FName MenuName)
{
	if (!IsValid(Theme) || !IsValid(MenuConfig) || !MenuConfig->Menus.Contains(MenuName))
	{
		return;
	}

	const FUltimateMenuMenuConfigData Menu = MenuConfig->Menus[MenuName];
	UUltimateMenuMenuAppearance* Appearance = IsValid(Menu.OverrideAppearance)
		? Menu.OverrideAppearance
		: (Theme->MenuAppearance.Contains(Menu.MenuType) ? Theme->MenuAppearance[Menu.MenuType] : nullptr);
	if (!IsValid(Appearance))
	{
		return;
	}

	UMenuWidget* MenuWidget = CreateWidget<UMenuWidget>(GetWorld(), Appearance->MenuWidgetClass);
	if (!IsValid(MenuWidget))
	{
		return;
	}

	MenuWidget->AddToViewport(ZOrder + Menus.Num());
	MenuWidget->LoadMenu(this, Appearance, Menu);

	if (!Menus.IsEmpty())
	{
		Menus.Last()->SetAsInactive();
	}
	
	Menus.Push(MenuWidget);
	Menus.Last()->SetAsActive();
}

void AMenuManager::PopMenu()
{
	if (Menus.IsEmpty())
	{
		return;
	}

	UMenuWidget* PoppedMenu = Menus.Pop();
	PoppedMenu->DisableInput();
	PoppedMenu->RemoveFromParent();
	
	if (!Menus.IsEmpty())
	{
		Menus.Last()->SetAsActive();
	}
}

void AMenuManager::ItemSelected(const FName CallbackId)
{
	ReceiveItemSelected(CallbackId);
}

void AMenuManager::BackNavigationPerformed(const FName CallbackId)
{
	ReceiveBackNavigationPerformed(CallbackId);
}

FText AMenuManager::GetText(const FName TextId)
{
	return ReceiveGetText(TextId);
}

void AMenuManager::EnableMenuInput()
{
	if (!Menus.IsEmpty())
	{
		Menus.Last()->EnableInput();
	}
}

void AMenuManager::DisableMenuInput()
{
	if (!Menus.IsEmpty())
	{
		Menus.Last()->DisableInput();
	}
}
