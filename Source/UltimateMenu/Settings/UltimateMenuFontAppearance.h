#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuFontAppearance.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuFontAppearance : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FSlateFontInfo Font;
};
