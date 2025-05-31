#include "FocusableWidget.h"

#include "UltimateMenu/Settings/UltimateMenuMenuItemAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuTheme.h"
#include "UltimateMenu/Utils/UltimateMenuUtils.h"

void UFocusableWidget::UpdateConfig(const EUltimateMenuMenuType MenuType,
	const FUltimateMenuMenuItemConfig& MenuItemConfig)
{
	Type = MenuType;
	Config = MenuItemConfig;

	const UUltimateMenuMenuItemAppearance* Appearance = IsValid(MenuItemConfig.OverrideAppearance)
		? MenuItemConfig.OverrideAppearance
		: (Theme->MenuItemAppearance.Contains(MenuType) ? Theme->MenuItemAppearance[MenuType] : nullptr);
	if (!IsValid(Appearance))
	{
		return;	
	}

	UUltimateMenuUtils::ApplySizeBoxConfig(SizeBox, Appearance->Size);
	UUltimateMenuUtils::ApplyLayoutConfig(this, Appearance->Layout);
}

void UFocusableWidget::ForceSelect()
{
	OnSelected.Broadcast(Config);
}

void UFocusableWidget::ForceFocus()
{
	UpdateFocus(true);
}

void UFocusableWidget::ForceUnfocus()
{
	UpdateFocus(false);
}

void UFocusableWidget::UpdateFocus(const bool IsFocused)
{
	if (!IsValid(Theme) || bIsFocused == IsFocused)
	{
		return;
	}

	bIsFocused = IsFocused;
	if (bIsFocused)
	{
		OnFocused.Broadcast(this);
	}
	
	ApplyThemeAfterFocusUpdate(bIsFocused);
}

void UFocusableWidget::ApplyThemeAfterFocusUpdate(bool IsFocused)
{
}
