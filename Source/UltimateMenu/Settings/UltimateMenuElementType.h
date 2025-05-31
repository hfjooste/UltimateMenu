#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuElementType.generated.h"

UENUM(BlueprintType)
enum class EUltimateMenuElementType : uint8
{
	Custom,
	Button,
	Image,
	Text
};