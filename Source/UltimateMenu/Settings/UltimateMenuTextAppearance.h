#pragma once

#include "CoreMinimal.h"
#include "Framework/Text/TextLayout.h"
#include "UltimateMenuColorValue.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuTextAppearance.generated.h"

class UUltimateMenuFontAppearance;

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuTextAppearance
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Font")
	UUltimateMenuFontAppearance* Font;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	FUltimateMenuLayoutConfig Layout;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<ETextJustify::Type> Justification;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color")
	FUltimateMenuColorValue TextColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color")
	FUltimateMenuColorValue ShadowColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color")
	FVector2D ShadowOffset;
};
