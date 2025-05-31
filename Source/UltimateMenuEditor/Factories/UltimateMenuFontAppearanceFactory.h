#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuFontAppearance.h"
#include "UltimateMenuFontAppearanceFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuFontAppearanceFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuFontAppearanceFactory()
	{
		DataAssetClass = UUltimateMenuFontAppearance::StaticClass();
		SupportedClass = UUltimateMenuFontAppearance::StaticClass();
	}
};
