#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuColorType.h"
#include "UltimateMenuColorValue.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuColorValue
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EUltimateMenuColorType Color;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Opacity = 1.0f;
};