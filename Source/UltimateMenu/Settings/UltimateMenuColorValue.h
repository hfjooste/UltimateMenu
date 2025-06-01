#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuColorType.h"
#include "UltimateMenuColorValue.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuColorValue
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color")
	EUltimateMenuColorType Color;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color")
	float Opacity = 1.0f;
};