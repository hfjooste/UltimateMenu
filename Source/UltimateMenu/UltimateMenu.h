#pragma once

#include "Modules/ModuleManager.h"

class FUltimateMenuModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
