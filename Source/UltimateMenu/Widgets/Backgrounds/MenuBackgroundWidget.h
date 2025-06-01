#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/BackgroundBlur.h"
#include "Components/Image.h"
#include "MenuBackgroundWidget.generated.h"

class UUltimateMenuMenuBackgroundConfig;

UCLASS()
class ULTIMATEMENU_API UMenuBackgroundWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate Menu", meta=(BindWidget))
	UImage* BackgroundImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate Menu", meta=(BindWidget))
	UImage* BorderImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate Menu", meta=(BindWidget))
	UBackgroundBlur* BelowBackgroundBlur;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate Menu", meta=(BindWidget))
	UBackgroundBlur* AboveBackgroundBlur;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void ApplyConfig(UUltimateMenuMenuBackgroundConfig* Config);
};
