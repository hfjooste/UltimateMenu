#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuItemCallbackType.generated.h"

UENUM(BlueprintType)
enum class EUltimateMenuMenuItemCallbackType : uint8
{
	None,
	PopMenu,
	PushMenu,
	LoadLevel,
	QuitGame,
	Custom
};