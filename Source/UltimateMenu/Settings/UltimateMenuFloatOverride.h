#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuFloatOverride.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuFloatOverride
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Float")
	bool bOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Float",
		meta=(EditCondition = "bOverride", EditConditionHides))
	float Value;
};