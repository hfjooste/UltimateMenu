#pragma once

#include "AssetTypeCategories.h"
#include "IAssetTools.h"
#include "IAssetTypeActions.h"

class FUltimateMenuEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	static IModuleInterface& Get();
	static bool IsAvailable();

private:
	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
	void RegisterAssetTypeAction(IAssetTools& AssetTools, const TSharedRef<IAssetTypeActions>& Action);
	void RegisterDataAsset(IAssetTools& AssetTools, EAssetTypeCategories::Type Category,
		const FString& SubMenu, const FString& AssetName, FColor AssetColor, UClass* AssetClass);
};
