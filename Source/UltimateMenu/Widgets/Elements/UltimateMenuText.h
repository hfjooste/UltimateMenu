#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "UltimateMenu/Settings/UltimateMenuTextAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuTextValue.h"
#include "UltimateMenu/Widgets/Base/ThemeableWidget.h"
#include "UltimateMenuText.generated.h"

class AMenuManager;

UCLASS()
class ULTIMATEMENU_API UUltimateMenuText : public UThemeableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate Menu", meta=(BindWidget))
	UTextBlock* TextBlock;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void InitializeText(AMenuManager* Manager, const FUltimateMenuTextValue& Text,
		const FUltimateMenuTextAppearance& TextAppearance);

protected:
	virtual void ApplyTheme(UUltimateMenuTheme* AppliedTheme) override;

private:
	FUltimateMenuTextAppearance Appearance;
};
