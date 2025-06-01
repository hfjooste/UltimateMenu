#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuTextType.h"
#include "UltimateMenuTextValue.generated.h"

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuTextValue
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Text")
	EUltimateMenuTextType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta=(EditCondition = "Type == EUltimateMenuTextType::Static", EditConditionHides))
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta=(EditCondition = "Type == EUltimateMenuTextType::Dynamic", EditConditionHides))
	FName TextId;
};