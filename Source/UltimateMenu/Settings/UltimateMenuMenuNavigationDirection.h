#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuNavigationDirection.generated.h"

UENUM(BlueprintType)
enum class EUltimateMenuMenuNavigationDirection : uint8
{
	Vertical,
	Horizontal,
	Tab
};