#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuBehaviourInactive.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuBehaviourInactive
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAlwaysActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bUnpauseWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bHideWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bBlurScreenWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,
		meta=(EditCondition = "!bAlwaysActive && bBlurScreenWhenInactive", EditConditionHides))
	float BlurScreenStrength = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bBlurMenuWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,
		meta=(EditCondition = "!bAlwaysActive && bBlurMenuWhenInactive", EditConditionHides))
	float BlurMenuStrength = 30.0f;
};