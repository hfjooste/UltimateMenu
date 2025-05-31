#include "UltimateMenuButton.h"

#include "UltimateMenuImage.h"
#include "UltimateMenu/Settings/UltimateMenuButtonAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuTheme.h"
#include "UltimateMenu/Utils/UltimateMenuUtils.h"

void UUltimateMenuButton::InitializeButton(AMenuManager* Manager, const EUltimateMenuMenuType MenuType,
	const FUltimateMenuMenuItemConfig& MenuItemConfig)
{
	UpdateConfig(MenuType, MenuItemConfig);
	ApplyThemeAfterFocusUpdate(false);

	UUltimateMenuUtils::ApplyText(TextBlock, Manager, MenuItemConfig.Text);
	Button->OnHovered.AddDynamic(this, &UUltimateMenuButton::ForceFocus);
	Button->OnClicked.AddDynamic(this, &UUltimateMenuButton::ForceSelect);
}

void UUltimateMenuButton::ApplyTheme(UUltimateMenuTheme* AppliedTheme)
{
	Super::ApplyTheme(AppliedTheme);
	ApplyThemeAfterFocusUpdate(false);
}

void UUltimateMenuButton::ApplyThemeAfterFocusUpdate(const bool IsFocused)
{
	Super::ApplyThemeAfterFocusUpdate(IsFocused);
	if (!IsValid(Theme))
	{
		return;
	}
	
	const UUltimateMenuButtonAppearance* Appearance = IsValid(Config.OverrideButtonAppearance)
		? Config.OverrideButtonAppearance
		: (Theme->ButtonAppearance.Contains(Type) ? Theme->ButtonAppearance[Type] : nullptr);
	if (!IsValid(Appearance))
	{
		return;
	}

	if (IsValid(BackgroundImage))
	{
		const FSlateBrush BackgroundBrush = IsFocused
			? Appearance->FocusedBackgroundBrush
			: Appearance->DefaultBackgroundBrush;
		BackgroundImage->SetBrush(BackgroundBrush);

		const FUltimateMenuColorValue BackgroundColor = IsFocused
			? Appearance->FocusedBackgroundColor
			: Appearance->DefaultBackgroundColor;
		BackgroundImage->SetBrushTintColor(UUltimateMenuUtils::GetColorFromTheme(Theme, BackgroundColor));
	}

	if (IsValid(BorderImage))
	{
		const FSlateBrush BorderBrush = IsFocused
			? Appearance->FocusedBorderBrush
			: Appearance->DefaultBorderBrush;
		BorderImage->SetBrush(BorderBrush);
	
		const FUltimateMenuColorValue BorderColor = IsFocused
			? Appearance->FocusedBorderColor
			: Appearance->DefaultBorderColor;
		BorderImage->SetBrushTintColor(UUltimateMenuUtils::GetColorFromTheme(Theme, BorderColor));
	}

	UUltimateMenuUtils::ApplyLayoutConfig(Content, Appearance->ContentLayout);
	UUltimateMenuUtils::ApplyTextAppearance(TextBlock, IsFocused
		? Appearance->FocusedTextAppearance
		: Appearance->DefaultTextAppearance);

	if (IsValid(LeftImage))
	{
		UUltimateMenuImageAppearance* LeftImageAppearance = IsFocused
			? (IsValid(Config.OverrideFocusedLeftImageAppearance)
				? Config.OverrideFocusedLeftImageAppearance
				: Appearance->FocusedLeftImageAppearance)
			: (IsValid(Config.OverrideDefaultLeftImageAppearance)
				? Config.OverrideDefaultLeftImageAppearance
				: Appearance->DefaultLeftImageAppearance);
		LeftImage->InitializeImage(LeftImageAppearance);	
	}

	if (IsValid(RightImage))
	{
		UUltimateMenuImageAppearance* RightImageAppearance = IsFocused
			? (IsValid(Config.OverrideFocusedRightImageAppearance)
				? Config.OverrideFocusedRightImageAppearance
				: Appearance->FocusedRightImageAppearance)
			: (IsValid(Config.OverrideDefaultRightImageAppearance)
				? Config.OverrideDefaultRightImageAppearance
				: Appearance->DefaultRightImageAppearance);
		RightImage->InitializeImage(RightImageAppearance);	
	}

	if (IsValid(TopImage))
	{
		UUltimateMenuImageAppearance* TopImageAppearance = IsFocused
			? (IsValid(Config.OverrideFocusedTopImageAppearance)
				? Config.OverrideFocusedTopImageAppearance
				: Appearance->FocusedTopImageAppearance)
			: (IsValid(Config.OverrideDefaultTopImageAppearance)
				? Config.OverrideDefaultTopImageAppearance
				: Appearance->DefaultTopImageAppearance);
		TopImage->InitializeImage(TopImageAppearance);	
	}	

	if (IsValid(BottomImage))
	{
		UUltimateMenuImageAppearance* BottomImageAppearance = IsFocused
			? (IsValid(Config.OverrideFocusedBottomImageAppearance)
				? Config.OverrideFocusedBottomImageAppearance
				: Appearance->FocusedBottomImageAppearance)
			: (IsValid(Config.OverrideDefaultBottomImageAppearance)
				? Config.OverrideDefaultBottomImageAppearance
				: Appearance->DefaultBottomImageAppearance);
		BottomImage->InitializeImage(BottomImageAppearance);	
	}
}
