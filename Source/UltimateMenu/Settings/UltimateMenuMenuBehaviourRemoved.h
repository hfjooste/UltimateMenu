#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuBehaviourRemoved.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuBehaviourRemoved
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bUnpauseWhenRemoved;
};