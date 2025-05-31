#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuButtonAppearance.h"
#include "UltimateMenuButtonAppearanceFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuButtonAppearanceFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuButtonAppearanceFactory()
	{
		DataAssetClass = UUltimateMenuButtonAppearance::StaticClass();
		SupportedClass = UUltimateMenuButtonAppearance::StaticClass();
	}
};
