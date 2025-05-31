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
	UFUNCTION(BlueprintCallable)
	void EnableInput() const;

	UFUNCTION(BlueprintCallable)
	void DisableInput() const;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	virtual void NavigateUp();
	
	UFUNCTION(BlueprintCallable)
	virtual void NavigateDown();
	
	UFUNCTION(BlueprintCallable)
	virtual void NavigateLeft();
	
	UFUNCTION(BlueprintCallable)
	virtual void NavigateRight();
	
	UFUNCTION(BlueprintCallable)
	virtual void TabLeft();
	
	UFUNCTION(BlueprintCallable)
	virtual void TabRight();
	
	UFUNCTION(BlueprintCallable)
	virtual void Select();
	
	UFUNCTION(BlueprintCallable)
	virtual void Back();

private:
	UPROPERTY()
	UUltimateMenuInputComponent* WidgetInputComponent;
};
