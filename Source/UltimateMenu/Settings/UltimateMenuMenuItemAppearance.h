#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuSizeBoxConfig.h"
#include "UltimateMenuMenuItemAppearance.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuMenuItemAppearance : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuSizeBoxConfig Size;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuLayoutConfig Layout;
};
