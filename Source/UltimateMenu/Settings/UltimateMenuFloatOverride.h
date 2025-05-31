#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuFloatOverride.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuFloatOverride
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "bOverride", EditConditionHides))
	float Value;
};