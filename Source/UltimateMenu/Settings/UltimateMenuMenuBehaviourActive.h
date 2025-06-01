#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuBehaviourActive.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuBehaviourActive
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Active")
	bool bPauseWhenActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Active")
	bool bBlurScreenWhenActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Active",
		meta=(EditCondition = "bBlurScreenWhenActive", EditConditionHides))
	float BlurScreenStrength = 30.0f;
};