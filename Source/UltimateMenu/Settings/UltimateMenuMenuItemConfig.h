#pragma once

#include "CoreMinimal.h"
#include "UltimateMenuElementType.h"
#include "UltimateMenuMenuItemCallbackType.h"
#include "UltimateMenuTextAppearance.h"
#include "UltimateMenuTextValue.h"
#include "UltimateMenuMenuItemConfig.generated.h"

class UUltimateMenuImageAppearance;
class UUltimateMenuButtonAppearance;
class UUltimateMenuMenuItemAppearance;
class UThemeableWidget;

USTRUCT(BlueprintType)
struct ULTIMATEMENU_API FUltimateMenuMenuItemConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	TSubclassOf<UThemeableWidget> WidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	EUltimateMenuElementType ElementType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Text",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button || ElementType == EUltimateMenuElementType::Text",
			EditConditionHides))
	FUltimateMenuTextValue Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuMenuItemAppearance* OverrideAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuButtonAppearance* OverrideButtonAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideDefaultLeftImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideFocusedLeftImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideDefaultRightImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideFocusedRightImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideDefaultTopImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideFocusedTopImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideDefaultBottomImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	UUltimateMenuImageAppearance* OverrideFocusedBottomImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Image", EditConditionHides))
	UUltimateMenuImageAppearance* ImageAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Appearance",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Text", EditConditionHides))
	FUltimateMenuTextAppearance TextAppearance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callback",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button", EditConditionHides))
	EUltimateMenuMenuItemCallbackType CallbackType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callback",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button && CallbackType == EUltimateMenuMenuItemCallbackType::PushMenu",
			EditConditionHides))
	FName MenuName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callback",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button && CallbackType == EUltimateMenuMenuItemCallbackType::LoadLevel",
			EditConditionHides))
	FName LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callback",
		meta=(EditCondition = "ElementType == EUltimateMenuElementType::Button && CallbackType == EUltimateMenuMenuItemCallbackType::Custom",
			EditConditionHides))
	FName CallbackId;
};