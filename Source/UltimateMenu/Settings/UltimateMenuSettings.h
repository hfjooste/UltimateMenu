#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "UltimateMenuSettings.generated.h"

class UUltimateMenuTheme;
class UUltimateMenuMenuConfig;

UCLASS(ClassGroup=UltimateMenu, Config=Game, DefaultConfig)
class ULTIMATEMENU_API UUltimateMenuSettings : public UObject
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> NavigateUpInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> NavigateDownInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> NavigateLeftInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> NavigateRightInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> TabLeftInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> TabRightInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> SelectInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Input")
	TSoftObjectPtr<UInputAction> BackInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Theme")
	TSoftObjectPtr<UUltimateMenuTheme> Theme;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category = "Ultimate Menu|Menus")
	TSoftObjectPtr<UUltimateMenuMenuConfig> Menus;
};