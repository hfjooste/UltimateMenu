#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuFloatOverride.h"
#include "UltimateMenuSizeBoxConfig.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuSizeBoxConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride Width;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride MinWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride MaxWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride Height;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride MinHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride MaxHeight;
};