#include "UltimateMenuAsset.h"

FUltimateMenuAsset::FUltimateMenuAsset(const EAssetTypeCategories::Type Category, const FString& SubMenu,
	const FString& Name, const FColor Color, UClass* Class) :
		AssetCategory(Category), AssetName(Name), AssetColor(Color), AssetClass(Class)
{
	AssetSubMenu = TArray<FText>();
	if (!SubMenu.IsEmpty())
	{
		AssetSubMenu.Add(FText::FromString(SubMenu));
	}
}

FText FUltimateMenuAsset::GetName() const
{
	return FText::FromString(AssetName);
}

FColor FUltimateMenuAsset::GetTypeColor() const
{
	return AssetColor;
}

UClass* FUltimateMenuAsset::GetSupportedClass() const
{
	return AssetClass;
}

const TArray<FText>& FUltimateMenuAsset::GetSubMenus() const
{
	return AssetSubMenu;
}

uint32 FUltimateMenuAsset::GetCategories()
{
	return AssetCategory;
}