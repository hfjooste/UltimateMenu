#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuBehaviourActive.h"
#include "UltimateMenuMenuBehaviourInactive.h"
#include "UltimateMenuMenuBehaviourRemoved.h"
#include "UltimateMenuMenuBehaviour.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuBehaviour
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Behaviour")
	FUltimateMenuMenuBehaviourActive Active;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Behaviour")
	FUltimateMenuMenuBehaviourInactive Inactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Behaviour")
	FUltimateMenuMenuBehaviourRemoved Removed;
};