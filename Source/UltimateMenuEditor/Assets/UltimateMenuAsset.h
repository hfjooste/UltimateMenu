#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class ULTIMATEMENUEDITOR_API FUltimateMenuAsset : public FAssetTypeActions_Base
{	
public:
	FUltimateMenuAsset(EAssetTypeCategories::Type Category, const FString& SubMenu,
		const FString& Name, FColor Color, UClass* Class);
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual const TArray<FText>& GetSubMenus() const override;
	virtual uint32 GetCategories() override;

private:
	EAssetTypeCategories::Type AssetCategory;
	TArray<FText> AssetSubMenu;
	FString AssetName;
	FColor AssetColor;
	UClass* AssetClass;
};