#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ThemeableWidget.generated.h"

class UUltimateMenuTheme;

UCLASS()
class ULTIMATEMENU_API UThemeableWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ultimate Menu")
	UUltimateMenuTheme* Theme;
	
	virtual void NativePreConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void ApplyTheme(UUltimateMenuTheme* AppliedTheme);
};
