#pragma once

#include "CoreMinimal.h"
#include "Factories/DataAssetFactory.h"
#include "UltimateMenuDataAssetFactory.generated.h"

UCLASS()
class ULTIMATEMENUEDITOR_API UUltimateMenuDataAssetFactory : public UDataAssetFactory
{
	GENERATED_BODY()

public:
	UUltimateMenuDataAssetFactory();

	virtual bool ConfigureProperties() override;

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
		UObject* Context, FFeedbackContext* Warn) override;
};