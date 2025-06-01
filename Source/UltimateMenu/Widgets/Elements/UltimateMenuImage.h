#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "UltimateMenu/Widgets/Base/ThemeableWidget.h"
#include "UltimateMenuImage.generated.h"

class UUltimateMenuImageAppearance;

UCLASS()
class ULTIMATEMENU_API UUltimateMenuImage : public UThemeableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ultimate Menu", meta=(BindWidget))
	UImage* Image;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void InitializeImage(UUltimateMenuImageAppearance* ImageAppearance);

protected:
	virtual void ApplyTheme(UUltimateMenuTheme* AppliedTheme) override;

private:
	UPROPERTY()
	UUltimateMenuImageAppearance* Appearance;
};
