#pragma once

#include "CoreMinimal.h"
#include "ThemeableWidget.h"
#include "Components/SizeBox.h"
#include "UltimateMenu/Settings/UltimateMenuMenuItemConfig.h"
#include "UltimateMenu/Settings/UltimateMenuMenuType.h"
#include "FocusableWidget.generated.h"

UCLASS()
class ULTIMATEMENU_API UFocusableWidget : public UThemeableWidget
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFocusableWidgetFocusedDelegate, UWidget*, Item);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUltimateMenuButtonSelectedDelegate,
		const FUltimateMenuMenuItemConfig&, Config);
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate Menu", meta=(BindWidget))
	USizeBox* SizeBox;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FFocusableWidgetFocusedDelegate OnFocused;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuButtonSelectedDelegate OnSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ultimate Menu")
	EUltimateMenuMenuType Type;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void UpdateConfig(EUltimateMenuMenuType MenuType, const FUltimateMenuMenuItemConfig& MenuItemConfig);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void ForceSelect();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void ForceFocus();

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void ForceUnfocus();

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void UpdateFocus(bool IsFocused);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ultimate Menu")
	FUltimateMenuMenuItemConfig Config;
	
	virtual void ApplyThemeAfterFocusUpdate(bool IsFocused);

private:
	bool bIsFocused;
};
