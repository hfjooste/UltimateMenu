#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuMenuConfig.h"
#include "UltimateMenuMenuConfigFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuMenuConfigFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuMenuConfigFactory()
	{
		DataAssetClass = UUltimateMenuMenuConfig::StaticClass();
		SupportedClass = UUltimateMenuMenuConfig::StaticClass();
	}
};
