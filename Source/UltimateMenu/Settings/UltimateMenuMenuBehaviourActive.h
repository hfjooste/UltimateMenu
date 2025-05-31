#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuBehaviourActive.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuBehaviourActive
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bPauseWhenActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bBlurScreenWhenActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "bBlurScreenWhenActive", EditConditionHides))
	float BlurScreenStrength = 30.0f;
};