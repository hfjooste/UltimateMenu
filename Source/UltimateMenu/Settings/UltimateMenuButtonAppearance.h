#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuColorValue.h"
#include "UltimateMenuLayoutConfig.h"
#include "UltimateMenuTextAppearance.h"
#include "UltimateMenuImageAppearance.h"
#include "UltimateMenuButtonAppearance.generated.h"

UCLASS()
class ULTIMATEMENU_API UUltimateMenuButtonAppearance : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Layout")
	FUltimateMenuLayoutConfig ContentLayout;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	FSlateBrush DefaultBackgroundBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	FSlateBrush FocusedBackgroundBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	FUltimateMenuColorValue DefaultBackgroundColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background")
	FUltimateMenuColorValue FocusedBackgroundColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Border")
	FSlateBrush DefaultBorderBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Border")
	FSlateBrush FocusedBorderBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Border")
	FUltimateMenuColorValue DefaultBorderColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Border")
	FUltimateMenuColorValue FocusedBorderColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Text")
	FUltimateMenuTextAppearance DefaultTextAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Text")
	FUltimateMenuTextAppearance FocusedTextAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Left")
	UUltimateMenuImageAppearance* DefaultLeftImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Left")
	UUltimateMenuImageAppearance* FocusedLeftImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Right")
	UUltimateMenuImageAppearance* DefaultRightImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Right")
	UUltimateMenuImageAppearance* FocusedRightImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Top")
	UUltimateMenuImageAppearance* DefaultTopImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Top")
	UUltimateMenuImageAppearance* FocusedTopImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Bottom")
	UUltimateMenuImageAppearance* DefaultBottomImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Images|Bottom")
	UUltimateMenuImageAppearance* FocusedBottomImageAppearance;
};
