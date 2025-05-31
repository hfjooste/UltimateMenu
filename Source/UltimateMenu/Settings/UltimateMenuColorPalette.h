#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuColorType.h"
#include "UltimateMenuColorPalette.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuColorPalette : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EUltimateMenuColorType, FLinearColor> Colors;
};
