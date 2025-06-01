#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UltimateMenuColorType.h"
#include "UltimateMenuColorPalette.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuColorPalette : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Colors")
	TMap<EUltimateMenuColorType, FLinearColor> Colors;
};
