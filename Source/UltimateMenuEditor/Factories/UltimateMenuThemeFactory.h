#pragma once

#include "CoreMinimal.h"
#include "Base/UltimateMenuDataAssetFactory.h"
#include "UltimateMenu/Settings/UltimateMenuTheme.h"
#include "UltimateMenuThemeFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuThemeFactory : public UUltimateMenuDataAssetFactory
{
	GENERATED_BODY()
	
public:
	UUltimateMenuThemeFactory()
	{
		DataAssetClass = UUltimateMenuTheme::StaticClass();
		SupportedClass = UUltimateMenuTheme::StaticClass();
	}
};
