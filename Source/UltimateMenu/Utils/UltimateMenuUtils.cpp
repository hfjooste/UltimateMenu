#include "UltimateMenuUtils.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/OverlaySlot.h"
#include "Components/VerticalBoxSlot.h"
#include "UltimateMenu/Core/MenuManager.h"
#include "UltimateMenu/Settings/UltimateMenuColorPalette.h"
#include "UltimateMenu/Settings/UltimateMenuFontAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuSettings.h"
#include "UltimateMenu/Settings/UltimateMenuTheme.h"

UUltimateMenuTheme* UUltimateMenuUtils::GetTheme()
{
	const UUltimateMenuSettings* Settings = GetDefault<UUltimateMenuSettings>();
	return IsValid(Settings) ? Settings->Theme.LoadSynchronous() : nullptr;
}

FLinearColor UUltimateMenuUtils::GetColor(const FUltimateMenuColorValue& Color)
{
	return GetColorFromTheme(GetTheme(), Color);
}

FLinearColor UUltimateMenuUtils::GetColorFromTheme(const UUltimateMenuTheme* Theme, const FUltimateMenuColorValue& Color)
{
	if (!IsValid(Theme) || !IsValid(Theme->ColorPalette) || !Theme->ColorPalette->Colors.Contains(Color.Color))
	{
		return FLinearColor::Transparent;
	}

	const FLinearColor ThemeColor = Theme->ColorPalette->Colors[Color.Color];
	return FLinearColor(ThemeColor.R, ThemeColor.G, ThemeColor.B, ThemeColor.A * Color.Opacity);
}

void UUltimateMenuUtils::ApplyText(UTextBlock* TextBlock, AMenuManager* Manager, const FUltimateMenuTextValue& Text)
{
	if (!IsValid(TextBlock) || !IsValid(Manager))
	{
		return;
	}

	switch (Text.Type)
	{
	case EUltimateMenuTextType::Static:
		TextBlock->SetText(Text.Text);
		break;
	case EUltimateMenuTextType::Dynamic:
		TextBlock->SetText(Manager->GetText(Text.TextId));
		break;
	}
}

void UUltimateMenuUtils::ApplyTextAppearance(UTextBlock* TextBlock, const FUltimateMenuTextAppearance& Appearance)
{
	if (!IsValid(TextBlock))
	{
		return;
	}

	const UUltimateMenuTheme* Theme = GetTheme();
	if (!IsValid(Theme))
	{
		return;
	}

	if (IsValid(Appearance.Font))
	{
		TextBlock->SetFont(Appearance.Font->Font);	
	}
	
	TextBlock->SetJustification(Appearance.Justification);
	TextBlock->SetColorAndOpacity(GetColorFromTheme(Theme, Appearance.TextColor));
	TextBlock->SetShadowColorAndOpacity(GetColorFromTheme(Theme, Appearance.ShadowColor));
	TextBlock->SetShadowOffset(Appearance.ShadowOffset);

	ApplyLayoutConfig(TextBlock, Appearance.Layout);
}

void UUltimateMenuUtils::ApplyImageAppearance(UImage* Image, const UUltimateMenuImageAppearance* Appearance)
{
	if (!IsValid(Image))
	{
		return;
	}

	if (!IsValid(Appearance))
	{
		Image->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}

	switch (Appearance->Type)
	{
	case EUltimateMenuImageType::Texture:
		Image->SetBrushFromTexture(Appearance->Texture, true);
		break;
	case EUltimateMenuImageType::Material:
		Image->SetBrushFromMaterial(Appearance->Material);
		break;
	}

	const FVector2D CurrentSize = Image->Brush.GetImageSize();
	Image->SetDesiredSizeOverride(FVector2D(
		Appearance->ImageWidth.bOverride ? Appearance->ImageWidth.Value : CurrentSize.X,
		Appearance->ImageHeight.bOverride ? Appearance->ImageHeight.Value : CurrentSize.Y));
	Image->SetBrushTintColor(Appearance->bApplyTint ? GetColor(Appearance->Tint) : FLinearColor::White);
	Image->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	ApplyLayoutConfig(Image, Appearance->Layout);
}

void UUltimateMenuUtils::ApplyLayoutConfig(UWidget* Widget, const FUltimateMenuLayoutConfig& Config)
{
	if (!IsValid(Widget))
	{
		return;
	}

	UOverlaySlot* OverlaySlot = UWidgetLayoutLibrary::SlotAsOverlaySlot(Widget);
	if (IsValid(OverlaySlot))
	{
		OverlaySlot->SetPadding(Config.Padding);
		OverlaySlot->SetHorizontalAlignment(Config.HorizontalAlignment);
		OverlaySlot->SetVerticalAlignment(Config.VerticalAlignment);
		return;
	}

	UVerticalBoxSlot* VerticalBoxSlot = UWidgetLayoutLibrary::SlotAsVerticalBoxSlot(Widget);
	if (IsValid(VerticalBoxSlot))
	{
		VerticalBoxSlot->SetPadding(Config.Padding);
		VerticalBoxSlot->SetHorizontalAlignment(Config.HorizontalAlignment);
		VerticalBoxSlot->SetVerticalAlignment(Config.VerticalAlignment);
		return;
	}

	UHorizontalBoxSlot* HorizontalBoxSlot = UWidgetLayoutLibrary::SlotAsHorizontalBoxSlot(Widget);
	if (IsValid(HorizontalBoxSlot))
	{
		HorizontalBoxSlot->SetPadding(Config.Padding);
		HorizontalBoxSlot->SetHorizontalAlignment(Config.HorizontalAlignment);
		HorizontalBoxSlot->SetVerticalAlignment(Config.VerticalAlignment);
	}
}

void UUltimateMenuUtils::ApplySizeBoxConfig(USizeBox* SizeBox, const FUltimateMenuSizeBoxConfig& Config)
{
	if (!IsValid(SizeBox))
	{
		return;
	}
	
	if (Config.Width.bOverride)
	{
		SizeBox->SetWidthOverride(Config.Width.Value);
	}

	if (Config.MinWidth.bOverride)
	{
		SizeBox->SetMinDesiredWidth(Config.MinWidth.Value);
	}

	if (Config.MaxWidth.bOverride)
	{
		SizeBox->SetMaxDesiredWidth(Config.MaxWidth.Value);
	}

	if (Config.Height.bOverride)
	{
		SizeBox->SetHeightOverride(Config.Height.Value);
	}

	if (Config.MinHeight.bOverride)
	{
		SizeBox->SetMinDesiredHeight(Config.MinHeight.Value);
	}

	if (Config.MaxHeight.bOverride)
	{
		SizeBox->SetMaxDesiredHeight(Config.MaxHeight.Value);
	}
}
