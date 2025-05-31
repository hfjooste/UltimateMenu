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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuMenuBehaviourActive Active;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuMenuBehaviourInactive Inactive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FUltimateMenuMenuBehaviourRemoved Removed;
};