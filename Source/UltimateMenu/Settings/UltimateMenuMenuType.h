#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuType.generated.h"

UENUM(BlueprintType)
enum class EUltimateMenuMenuType : uint8
{
	Custom,
	MainMenu,
	MainMenuSecondary,
	MainMenuTertiary,
	PauseMenu,
	PauseMenuSecondary,
	PauseMenuTertiary,
	SettingsMenu,
	SettingsMenuSecondary,
	SettingsMenuTertiary,
	PopupMenu
};