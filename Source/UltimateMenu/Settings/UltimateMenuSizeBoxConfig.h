#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuFloatOverride.h"
#include "UltimateMenuSizeBoxConfig.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuSizeBoxConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride Width;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride MinWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride MaxWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride Height;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride MinHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride MaxHeight;
};