#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuMenuBackgroundConfig.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuMenuBackgroundConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuLayoutConfig Layout;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FSlateBrush BackgroundBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FSlateBrush BorderBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bApplyBelowImageBlur;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "bApplyBelowImageBlur", EditConditionHides))
	float BelowImageBlurStrength = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bApplyAboveImageBlur;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "bApplyAboveImageBlur", EditConditionHides))
	float AboveImageBlurStrength = 30.0f;
};
