#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "UltimateMenu/Widgets/Base/FocusableWidget.h"
#include "UltimateMenuButton.generated.h"

class AMenuManager;
class UUltimateMenuImage;

UCLASS()
class ULTIMATEMENU_API UUltimateMenuButton : public UFocusableWidget
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UButton* Button;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UImage* BackgroundImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UImage* BorderImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UPanelWidget* Content;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* TextBlock;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UUltimateMenuImage* LeftImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UUltimateMenuImage* RightImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UUltimateMenuImage* TopImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(BindWidget))
	UUltimateMenuImage* BottomImage;

	UFUNCTION(BlueprintCallable)
	void InitializeButton(AMenuManager* Manager, EUltimateMenuMenuType MenuType,
		const FUltimateMenuMenuItemConfig& MenuItemConfig);

protected:
	virtual void ApplyTheme(UUltimateMenuTheme* AppliedTheme) override;
	virtual void ApplyThemeAfterFocusUpdate(bool IsFocused) override;
};
