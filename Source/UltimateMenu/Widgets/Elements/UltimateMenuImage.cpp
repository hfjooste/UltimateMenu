#include "UltimateMenuImage.h"

#include "UltimateMenu/Utils/UltimateMenuUtils.h"

void UUltimateMenuImage::InitializeImage(UUltimateMenuImageAppearance* ImageAppearance)
{
	Appearance = ImageAppearance;
	UUltimateMenuUtils::ApplyImageAppearance(Image, Appearance);
}

void UUltimateMenuImage::ApplyTheme(UUltimateMenuTheme* AppliedTheme)
{
	Super::ApplyTheme(AppliedTheme);
	UUltimateMenuUtils::ApplyImageAppearance(Image, Appearance);
}
