#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UltimateMenuMenuConfigData.h"
#include "UltimateMenuMenuConfig.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuMenuConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	TMap<FName, FUltimateMenuMenuConfigData> Menus;
};
