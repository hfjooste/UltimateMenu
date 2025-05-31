#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuLayoutConfig.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuLayoutConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment = HAlign_Fill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<EVerticalAlignment> VerticalAlignment = VAlign_Center;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FMargin Padding;
};