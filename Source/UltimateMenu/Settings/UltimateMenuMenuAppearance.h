#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UltimateMenuMenuBehaviour.h"
#include "UltimateMenuSizeBoxConfig.h"
#include "UltimateMenu/Widgets/Backgrounds/MenuBackgroundWidget.h"
#include "UltimateMenuMenuAppearance.generated.h"

class UMenuWidget;

UCLASS()
class ULTIMATEMENU_API UUltimateMenuMenuAppearance : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	TSubclassOf<UMenuWidget> MenuWidgetClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Size")
	FUltimateMenuSizeBoxConfig MenuSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Screen Position")
	TEnumAsByte<EHorizontalAlignment> ScreenHorizontalAlignment = HAlign_Center;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Screen Position")
	TEnumAsByte<EVerticalAlignment> ScreenVerticalAlignment = VAlign_Center;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Screen Position")
	FMargin ScreenPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<EHorizontalAlignment> MenuHorizontalAlignment = HAlign_Fill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	TEnumAsByte<EVerticalAlignment> MenuVerticalAlignment = VAlign_Fill;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	FMargin MenuPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	TSubclassOf<UMenuBackgroundWidget> BackgroundWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background",
		meta=(EditCondition = "BackgroundWidgetClass != nullptr", EditConditionHides))
	UUltimateMenuMenuBackgroundConfig* BackgroundConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Behaviour")
	FUltimateMenuMenuBehaviour Behaviour;
};
