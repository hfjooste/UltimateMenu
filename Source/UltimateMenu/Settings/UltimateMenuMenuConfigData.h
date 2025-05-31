#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuMenuBehaviour.h"
#include "UltimateMenuMenuItemConfig.h"
#include "UltimateMenuMenuType.h"
#include "Engine/DataTable.h"
#include "UltimateMenuMenuConfigData.generated.h"

class UUltimateMenuMenuAppearance;

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuConfigData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<FUltimateMenuMenuItemConfig> Items;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance")
	EUltimateMenuMenuType MenuType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance")
	UUltimateMenuMenuAppearance* OverrideAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Behaviour")
	bool bOverrideBehaviour;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Behaviour",
		meta=(EditCondition = "bOverrideBehaviour", EditConditionHides))
	FUltimateMenuMenuBehaviour Behaviour;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Back Callback")
	EUltimateMenuMenuItemCallbackType BackCallbackType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Back Callback",
		meta=(EditCondition = "BackCallbackType == EUltimateMenuMenuItemCallbackType::PushMenu", EditConditionHides))
	FName BackMenuName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Back Callback",
		meta=(EditCondition = "BackCallbackType == EUltimateMenuMenuItemCallbackType::LoadLevel", EditConditionHides))
	FName BackLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Back Callback",
		meta=(EditCondition = "BackCallbackType == EUltimateMenuMenuItemCallbackType::Custom", EditConditionHides))
	FName BackCallbackId;
};