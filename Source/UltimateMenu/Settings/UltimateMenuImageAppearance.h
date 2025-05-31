#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuColorValue.h"
#include "UltimateMenuFloatOverride.h"
#include "UltimateMenuImageType.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuImageAppearance.generated.h"
	
UCLASS()
class ULTIMATEMENU_API UUltimateMenuImageAppearance : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EUltimateMenuImageType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,
		meta=(EditCondition = "Type == EUltimateMenuImageType::Texture", EditConditionHides))
	UTexture2D* Texture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,
		meta=(EditCondition = "Type == EUltimateMenuImageType::Material", EditConditionHides))
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bApplyTint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(EditCondition = "bApplyTint", EditConditionHides))
	FUltimateMenuColorValue Tint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride ImageWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuFloatOverride ImageHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuLayoutConfig Layout;
};
