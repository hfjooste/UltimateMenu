#include "MenuBackgroundWidget.h"

#include "UltimateMenu/Settings/UltimateMenuMenuBackgroundConfig.h"
#include "UltimateMenu/Utils/UltimateMenuUtils.h"

void UMenuBackgroundWidget::ApplyConfig(UUltimateMenuMenuBackgroundConfig* Config)
{
	if (!IsValid(Config))
	{
		return;
	}

	BelowBackgroundBlur->SetVisibility(Config->bApplyBelowImageBlur
		? ESlateVisibility::HitTestInvisible
		: ESlateVisibility::Collapsed);
	BelowBackgroundBlur->SetBlurStrength(Config->BelowImageBlurStrength);

	AboveBackgroundBlur->SetVisibility(Config->bApplyAboveImageBlur
		? ESlateVisibility::HitTestInvisible
		: ESlateVisibility::Collapsed);
	AboveBackgroundBlur->SetBlurStrength(Config->AboveImageBlurStrength);
	
	BackgroundImage->SetBrush(Config->BackgroundBrush);
	BorderImage->SetBrush(Config->BorderBrush);

	UUltimateMenuUtils::ApplyLayoutConfig(this, Config->Layout);
}
