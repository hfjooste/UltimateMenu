#include "UltimateMenuText.h"

#include "UltimateMenu/Utils/UltimateMenuUtils.h"

void UUltimateMenuText::InitializeText(AMenuManager* Manager, const FUltimateMenuTextValue& Text,
	const FUltimateMenuTextAppearance& TextAppearance)
{	
	Appearance = TextAppearance;
	UUltimateMenuUtils::ApplyText(TextBlock, Manager, Text);
	UUltimateMenuUtils::ApplyTextAppearance(TextBlock, Appearance);
}

void UUltimateMenuText::ApplyTheme(UUltimateMenuTheme* AppliedTheme)
{
	Super::ApplyTheme(AppliedTheme);
	UUltimateMenuUtils::ApplyTextAppearance(TextBlock, Appearance);
}