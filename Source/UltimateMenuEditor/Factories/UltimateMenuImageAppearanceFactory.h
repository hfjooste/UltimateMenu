#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuImageAppearance.h"
#include "UltimateMenuImageAppearanceFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuImageAppearanceFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuImageAppearanceFactory()
	{
		DataAssetClass = UUltimateMenuImageAppearance::StaticClass();
		SupportedClass = UUltimateMenuImageAppearance::StaticClass();
	}
};
