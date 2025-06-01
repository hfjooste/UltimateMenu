#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuLayoutConfig.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuLayoutConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment = HAlign_Fill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment = VAlign_Center;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	FMargin Padding;
};