#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MenuManager.generated.h"

class UUltimateMenuMenuConfig;
class UUltimateMenuTheme;
class UMenuWidget;

UCLASS()
class ULTIMATEMENU_API AMenuManager : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ultimate Menu")
	FName InitialMenuName = NAME_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ultimate Menu")
	int ZOrder;
	
	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void PushMenu(FName MenuName);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void PopMenu();

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void ItemSelected(FName CallbackId);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ultimate Menu", meta=(DisplayName = "ItemSelected"))
	void ReceiveItemSelected(FName CallbackId);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	virtual void BackNavigationPerformed(FName CallbackId);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ultimate Menu", meta=(DisplayName = "BackNavigationPerformed"))
	void ReceiveBackNavigationPerformed(FName CallbackId);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Ultimate Menu")
	virtual FText GetText(FName TextId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category = "Ultimate Menu", meta=(DisplayName = "GetText"))
	FText ReceiveGetText(FName TextId);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void EnableMenuInput();

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void DisableMenuInput();

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
