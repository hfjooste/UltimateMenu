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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	USizeBox* SizeBox;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FFocusableWidgetFocusedDelegate OnFocused;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuButtonSelectedDelegate OnSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUltimateMenuMenuType Type;

	UFUNCTION(BlueprintCallable)
	void UpdateConfig(EUltimateMenuMenuType MenuType, const FUltimateMenuMenuItemConfig& MenuItemConfig);

	UFUNCTION(BlueprintCallable)
	void ForceSelect();
	
	UFUNCTION(BlueprintCallable)
	void ForceFocus();

	UFUNCTION(BlueprintCallable)
	void ForceUnfocus();

	UFUNCTION(BlueprintCallable)
	void UpdateFocus(bool IsFocused);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FUltimateMenuMenuItemConfig Config;
	
	virtual void ApplyThemeAfterFocusUpdate(bool IsFocused);

private:
	bool bIsFocused;
};
