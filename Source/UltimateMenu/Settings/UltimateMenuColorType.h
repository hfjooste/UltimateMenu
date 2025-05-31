#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuColorType.generated.h"

UENUM(BlueprintType)
enum class EUltimateMenuColorType : uint8
{
	None,
	Primary,
	PrimaryLight,
	PrimaryDark,
	Secondary,
	SecondaryLight,
	SecondaryDark,
	TextPrimary,
	TextPrimaryLight,
	TextPrimaryDark,
	TextSecondary,
	TextSecondaryLight,
	TextSecondaryDark,
	ShadowPrimary,
	ShadowPrimaryLight,
	ShadowPrimaryDark,
	ShadowSecondary,
	ShadowSecondaryLight,
	ShadowSecondaryDark,
};