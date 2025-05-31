#pragma once

#include "CoreMinimal.h"
#include "Components/BackgroundBlur.h"
#include "Components/Overlay.h"
#include "Components/SizeBox.h"
#include "UltimateMenu/Settings/UltimateMenuMenuConfigData.h"
#include "UltimateMenu/Settings/UltimateMenuMenuNavigationDirection.h"
#include "UltimateMenu/Widgets/Base/InputWidget.h"
#include "MenuWidget.generated.h"

class UUltimateMenuTheme;
class AMenuManager;
class UFocusableWidget;

UCLASS()
class ULTIMATEMENU_API UMenuWidget : public UInputWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EUltimateMenuMenuNavigationDirection NavigationDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UBackgroundBlur* BelowScreenBlur;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UBackgroundBlur* AboveScreenBlur;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UBackgroundBlur* MenuBlur;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	USizeBox* SizeBox;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UOverlay* BackgroundOverlay;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UPanelWidget* Content;

	UFUNCTION(BlueprintCallable)
	void LoadMenu(AMenuManager* Manager, UUltimateMenuMenuAppearance* Appearance,
		const FUltimateMenuMenuConfigData& NewMenuConfig);

	UFUNCTION(BlueprintCallable)
	void SetAsActive();

	UFUNCTION(BlueprintCallable)
	void SetAsInactive();

	virtual void RemoveFromParent() override;

protected:
	virtual void NavigateUp() override;
	virtual void NavigateDown() override;
	virtual void NavigateLeft() override;
	virtual void NavigateRight() override;
	virtual void TabLeft() override;
	virtual void TabRight() override;
	virtual void Select() override;
	virtual void Back() override;

private:
	UPROPERTY()
	AMenuManager* MenuManager;

	UPROPERTY()
	UUltimateMenuMenuAppearance* MenuAppearance;
	
	UPROPERTY()
	TArray<UFocusableWidget*> Items;

	FUltimateMenuMenuConfigData MenuConfig;
	FUltimateMenuMenuBehaviour MenuBehaviour;
	
	int SelectedIndex;

	void RefreshScreenPosition(const UUltimateMenuMenuAppearance* Appearance) const;
	void RefreshMenuPosition(const UUltimateMenuMenuAppearance* Appearance) const;
	void FocusNextItem();
	void FocusPreviousItem();

	void CreateButton(const FUltimateMenuMenuItemConfig& ItemConfig);
	void CreateImage(const FUltimateMenuMenuItemConfig& ItemConfig) const;
	void CreateText(const FUltimateMenuMenuItemConfig& ItemConfig) const;

	UFUNCTION()
	void ItemFocused(UWidget* Item);

	UFUNCTION()
	void ItemSelected(const FUltimateMenuMenuItemConfig& Config);
};
