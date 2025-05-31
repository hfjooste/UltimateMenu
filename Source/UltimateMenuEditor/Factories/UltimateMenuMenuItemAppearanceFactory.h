#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuMenuItemAppearance.h"
#include "UltimateMenuMenuItemAppearanceFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuMenuItemAppearanceFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuMenuItemAppearanceFactory()
	{
		DataAssetClass = UUltimateMenuMenuItemAppearance::StaticClass();
		SupportedClass = UUltimateMenuMenuItemAppearance::StaticClass();
	}
};
