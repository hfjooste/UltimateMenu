#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuMenuAppearance.h"
#include "UltimateMenuMenuAppearanceFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuMenuAppearanceFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuMenuAppearanceFactory()
	{
		DataAssetClass = UUltimateMenuMenuAppearance::StaticClass();
		SupportedClass = UUltimateMenuMenuAppearance::StaticClass();
	}
};
