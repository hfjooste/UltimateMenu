#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuColorValue.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuTextAppearance.generated.h"

class UUltimateMenuFontAppearance;

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuTextAppearance
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UUltimateMenuFontAppearance* Font;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuLayoutConfig Layout;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ETextJustify::Type> Justification;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuColorValue TextColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuColorValue ShadowColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector2D ShadowOffset;
};
