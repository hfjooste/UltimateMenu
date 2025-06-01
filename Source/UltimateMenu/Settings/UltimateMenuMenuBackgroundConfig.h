#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuMenuBackgroundConfig.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuMenuBackgroundConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	FUltimateMenuLayoutConfig Layout;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	FSlateBrush BackgroundBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	FSlateBrush BorderBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	bool bApplyBelowImageBlur;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background",
		meta=(EditCondition = "bApplyBelowImageBlur", EditConditionHides))
	float BelowImageBlurStrength = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	bool bApplyAboveImageBlur;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background",
		meta=(EditCondition = "bApplyAboveImageBlur", EditConditionHides))
	float AboveImageBlurStrength = 30.0f;
};
