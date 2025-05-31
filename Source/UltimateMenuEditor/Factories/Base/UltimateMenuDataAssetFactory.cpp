#include "UltimateMenuDataAssetFactory.h"

#include "Engine/DataAsset.h"

UUltimateMenuDataAssetFactory::UUltimateMenuDataAssetFactory()
{
	DataAssetClass = nullptr;
	SupportedClass = nullptr;
	bCreateNew = true;
	bEditAfterNew = true;
}

bool UUltimateMenuDataAssetFactory::ConfigureProperties()
{
	return true;
}

UObject* UUltimateMenuDataAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UDataAsset>(InParent, DataAssetClass, Name, Flags | RF_Transactional);
}