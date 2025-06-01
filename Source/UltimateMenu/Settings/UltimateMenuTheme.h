#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UltimateMenuMenuType.h"
#include "UltimateMenuTheme.generated.h"

class UUltimateMenuColorPalette;
class UUltimateMenuMenuAppearance;
class UUltimateMenuMenuItemAppearance;
class UUltimateMenuButtonAppearance;

UCLASS()
class ULTIMATEMENU_API UUltimateMenuTheme : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Colors")
	UUltimateMenuColorPalette* ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance")
	TMap<EUltimateMenuMenuType, UUltimateMenuMenuAppearance*> MenuAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance")
	TMap<EUltimateMenuMenuType, UUltimateMenuMenuItemAppearance*> MenuItemAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance")
	TMap<EUltimateMenuMenuType, UUltimateMenuButtonAppearance*> ButtonAppearance;
};
