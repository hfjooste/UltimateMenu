#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UltimateMenuInputComponent.generated.h"

class UUltimateMenuSettings;

UCLASS()
class UUltimateMenuInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputNavigateUpDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputNavigateDownDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputNavigateLeftDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputNavigateRightDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputTabLeftDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputTabRightDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputSelectDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUltimateMenuInputBackDelegate);

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputNavigateUpDelegate OnNavigateUp;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputNavigateDownDelegate OnNavigateDown;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputNavigateLeftDelegate OnNavigateLeft;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputNavigateRightDelegate OnNavigateRight;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputTabLeftDelegate OnTabLeft;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputTabRightDelegate OnTabRight;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputSelectDelegate OnSelect;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Ultimate Menu")
	FUltimateMenuInputBackDelegate OnBack;

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void Initialize(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void EnableInput();

	UFUNCTION(BlueprintCallable, Category = "Ultimate Menu")
	void DisableInput();
	
protected:
	virtual void BeginDestroy() override;

private:
	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY()
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem;

	UPROPERTY()
	UInputMappingContext* InputMappingContext;

	UFUNCTION()
	void NavigateUp();

	UFUNCTION()
	void NavigateDown();

	UFUNCTION()
	void NavigateLeft();

	UFUNCTION()
	void NavigateRight();

	UFUNCTION()
	void TabLeft();

	UFUNCTION()
	void TabRight();

	UFUNCTION()
	void Select();

	UFUNCTION()
	void Back();
};
