#include "UltimateMenuEditor.h"

#include "AssetToolsModule.h"
#include "Assets/UltimateMenuAsset.h"
#include "UltimateMenu/Settings/UltimateMenuButtonAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuColorPalette.h"
#include "UltimateMenu/Settings/UltimateMenuFontAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuMenuAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuMenuConfig.h"
#include "UltimateMenu/Settings/UltimateMenuMenuItemAppearance.h"
#include "UltimateMenu/Settings/UltimateMenuTheme.h"

#define LOCTEXT_NAMESPACE "FUltimateMenuEditorModule"

void FUltimateMenuEditorModule::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	const EAssetTypeCategories::Type UltimateMenuCategory = AssetTools.RegisterAdvancedAssetCategory(
		FName(TEXT("UltimateMenu")), FText::FromString("Ultimate Menu"));
	
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "", "Menu Config",
		FColor(56, 213, 0), UUltimateMenuMenuConfig::StaticClass());
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "", "Theme",
		FColor(255, 202, 35), UUltimateMenuTheme::StaticClass());
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "Colors", "Color Palette",
		FColor(255, 0, 212), UUltimateMenuColorPalette::StaticClass());
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "Appearance", "Button Appearance",
		FColor(201, 0, 0), UUltimateMenuButtonAppearance::StaticClass());
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "Appearance", "Font Appearance",
		FColor(201, 0, 0), UUltimateMenuFontAppearance::StaticClass());
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "Appearance", "Image Appearance",
		FColor(201, 0, 0), UUltimateMenuImageAppearance::StaticClass());
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "Appearance", "Menu Appearance",
		FColor(201, 0, 0), UUltimateMenuMenuAppearance::StaticClass());
	RegisterDataAsset(AssetTools, UltimateMenuCategory, "Appearance", "Menu Item Appearance",
		FColor(201, 0, 0), UUltimateMenuMenuItemAppearance::StaticClass());
}

void FUltimateMenuEditorModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); ++Index)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
		}
	}
}

IModuleInterface& FUltimateMenuEditorModule::Get()
{
	return FModuleManager::LoadModuleChecked<IModuleInterface>("UltimateMenuEditor");
}

bool FUltimateMenuEditorModule::IsAvailable()
{
	return FModuleManager::Get().IsModuleLoaded("UltimateMenuEditor");
}

void FUltimateMenuEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, const TSharedRef<IAssetTypeActions>& Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

void FUltimateMenuEditorModule::RegisterDataAsset(IAssetTools& AssetTools, const EAssetTypeCategories::Type Category,
	const FString& SubMenu, const FString& AssetName, const FColor AssetColor, UClass* AssetClass)
{
	FUltimateMenuAsset* Asset = new FUltimateMenuAsset(Category, SubMenu, AssetName, AssetColor, AssetClass);
	RegisterAssetTypeAction(AssetTools, MakeShareable(Asset));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUltimateMenuEditorModule, UltimateMenuEditor)