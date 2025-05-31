#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuColorPalette.h"
#include "UltimateMenuColorPaletteFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuColorPaletteFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuColorPaletteFactory()
	{
		DataAssetClass = UUltimateMenuColorPalette::StaticClass();
		SupportedClass = UUltimateMenuColorPalette::StaticClass();
	}
};
