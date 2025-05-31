#include "ThemeableWidget.h"

#include "UltimateMenu/Settings/UltimateMenuTheme.h"
#include "UltimateMenu/Utils/UltimateMenuUtils.h"

void UThemeableWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	UUltimateMenuTheme* CurrentTheme = UUltimateMenuUtils::GetTheme();
	if (IsValid(CurrentTheme))
	{
		ApplyTheme(CurrentTheme);
	}
}

void UThemeableWidget::ApplyTheme(UUltimateMenuTheme* AppliedTheme)
{
	Theme = AppliedTheme;
}
