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
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputNavigateUpDelegate OnNavigateUp;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputNavigateDownDelegate OnNavigateDown;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputNavigateLeftDelegate OnNavigateLeft;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputNavigateRightDelegate OnNavigateRight;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputTabLeftDelegate OnTabLeft;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputTabRightDelegate OnTabRight;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputSelectDelegate OnSelect;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUltimateMenuInputBackDelegate OnBack;

	UFUNCTION(BlueprintCallable)
	void Initialize(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable)
	void EnableInput();

	UFUNCTION(BlueprintCallable)
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
	void NavigateUp() const;

	UFUNCTION()
	void NavigateDown() const;

	UFUNCTION()
	void NavigateLeft() const;

	UFUNCTION()
	void NavigateRight() const;

	UFUNCTION()
	void TabLeft() const;

	UFUNCTION()
	void TabRight() const;

	UFUNCTION()
	void Select() const;

	UFUNCTION()
	void Back() const;
};
