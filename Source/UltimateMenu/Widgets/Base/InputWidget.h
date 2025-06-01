#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InputWidget.generated.h"

class UUltimateMenuInputComponent;

UCLASS()
class ULTIMATEMENU_API UInputWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void EnableInput() const;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void DisableInput() const;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void NavigateUp();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void NavigateDown();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void NavigateLeft();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void NavigateRight();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void TabLeft();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void TabRight();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void Select();
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void Back();

private:
	UPROPERTY()
	UUltimateMenuInputComponent* WidgetInputComponent;
};
