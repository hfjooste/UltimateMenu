#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Type")
	EUltimateMenuImageType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Image",
		meta=(EditCondition = "Type == EUltimateMenuImageType::Texture", EditConditionHides))
	UTexture2D* Texture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Image",
		meta=(EditCondition = "Type == EUltimateMenuImageType::Material", EditConditionHides))
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color")
	bool bApplyTint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Color",
		meta=(EditCondition = "bApplyTint", EditConditionHides))
	FUltimateMenuColorValue Tint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride ImageWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuFloatOverride ImageHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	FUltimateMenuLayoutConfig Layout;
};
