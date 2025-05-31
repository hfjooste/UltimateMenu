#pragma once

#include "CoreMinimal.h"
#include "UltimateMenu/Settings/UltimateMenuTextValue.h"
#include "MenuManager.generated.h"

class UUltimateMenuMenuConfig;
class UUltimateMenuTheme;
class UMenuWidget;

UCLASS()
class ULTIMATEMENU_API AMenuManager : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName InitialMenuName = NAME_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int ZOrder;
	
	UFUNCTION(BlueprintCallable)
	void PushMenu(FName MenuName);

	UFUNCTION(BlueprintCallable)
	void PopMenu();

	UFUNCTION(BlueprintCallable)
	virtual void ItemSelected(FName CallbackId);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "ItemSelected"))
	void ReceiveItemSelected(FName CallbackId);

	UFUNCTION(BlueprintCallable)
	virtual void BackNavigationPerformed(FName CallbackId);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "BackNavigationPerformed"))
	void ReceiveBackNavigationPerformed(FName CallbackId);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FText GetText(FName TextId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, meta=(DisplayName = "GetText"))
	FText ReceiveGetText(FName TextId);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UUltimateMenuTheme* Theme;

	UPROPERTY()
	UUltimateMenuMenuConfig* MenuConfig;
	
	UPROPERTY()
	TArray<UMenuWidget*> Menus;
};
