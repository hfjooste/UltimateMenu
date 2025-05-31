#include "UltimateMenu.h"

#include "Settings/UltimateMenuSettings.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#endif

#define LOCTEXT_NAMESPACE "FUltimateMenuModule"

void FUltimateMenuModule::StartupModule()
{
#if WITH_EDITOR
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule == nullptr)
	{
		return;
	}

	UUltimateMenuSettings* Settings = GetMutableDefault<UUltimateMenuSettings>();
	if (!IsValid(Settings))
	{
		return;
	}
	
	SettingsModule->RegisterSettings("Project", "Ultimate Menu", "Ultimate Menu",
			FText::FromString("Ultimate Menu"),
			FText::FromString("Settings for the Ultimate Menu"), Settings);
#endif
	
}

void FUltimateMenuModule::ShutdownModule()
{
#if WITH_EDITOR
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Ultimate Menu", "Ultimate Menu");
	}
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUltimateMenuModule, UltimateMenu)