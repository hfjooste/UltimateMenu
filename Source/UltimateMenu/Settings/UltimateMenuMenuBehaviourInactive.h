#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuBehaviourInactive.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuBehaviourInactive
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inactive")
	bool bAlwaysActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inactive",
		meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bUnpauseWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inactive",
		meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bHideWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inactive",
		meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bBlurScreenWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inactive",
		meta=(EditCondition = "!bAlwaysActive && bBlurScreenWhenInactive", EditConditionHides))
	float BlurScreenStrength = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inactive",
		meta=(EditCondition = "!bAlwaysActive", EditConditionHides))
	bool bBlurMenuWhenInactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inactive",
		meta=(EditCondition = "!bAlwaysActive && bBlurMenuWhenInactive", EditConditionHides))
	float BlurMenuStrength = 30.0f;
};