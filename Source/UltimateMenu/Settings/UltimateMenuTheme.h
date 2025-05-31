#pragma once

#include "CoreMinimal.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UUltimateMenuColorPalette* ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EUltimateMenuMenuType, UUltimateMenuMenuAppearance*> MenuAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EUltimateMenuMenuType, UUltimateMenuMenuItemAppearance*> MenuItemAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<EUltimateMenuMenuType, UUltimateMenuButtonAppearance*> ButtonAppearance;
};
