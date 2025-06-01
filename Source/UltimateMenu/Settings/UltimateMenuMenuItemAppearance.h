#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuSizeBoxConfig.h"
#include "UltimateMenuMenuItemAppearance.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuMenuItemAppearance : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuSizeBoxConfig Size;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	FUltimateMenuLayoutConfig Layout;
};
