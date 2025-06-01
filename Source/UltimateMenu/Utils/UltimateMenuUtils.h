#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "UltimateMenu/Settings/UltimateMenuColorValue.h"
#include "UltimateMenu/Settings/UltimateMenuImageAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuSizeBoxConfig.h"
#include "UltimateMenu/Settings/UltimateMenuTextAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuTextValue.h"
#include "UltimateMenuUtils.generated.h"

class AMenuManager;
class UUltimateMenuTheme;

UCLASS()
class ULTIMATEMENU_API UUltimateMenuUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ultimate Menu")
	static UUltimateMenuTheme* GetTheme();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ultimate Menu")
	static FLinearColor GetColor(const FUltimateMenuColorValue& Color);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ultimate Menu")
	static FLinearColor GetColorFromTheme(const UUltimateMenuTheme* Theme, const FUltimateMenuColorValue& Color);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	static void ApplyText(UTextBlock* TextBlock, AMenuManager* Manager, const FUltimateMenuTextValue& Text);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	static void ApplyTextAppearance(UTextBlock* TextBlock, const FUltimateMenuTextAppearance& Appearance);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	static void ApplyImageAppearance(UImage* Image, const UUltimateMenuImageAppearance* Appearance);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	static void ApplyLayoutConfig(UWidget* Widget, const FUltimateMenuLayoutConfig& Config);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	static void ApplySizeBoxConfig(USizeBox* SizeBox, const FUltimateMenuSizeBoxConfig& Config);
};
