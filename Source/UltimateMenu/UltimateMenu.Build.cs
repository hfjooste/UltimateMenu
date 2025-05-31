using UnrealBuildTool;

public class UltimateMenu : ModuleRules
{
	public UltimateMenu(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
		
		PrivateIncludePaths.AddRange(new string[] { });
		PublicIncludePaths.AddRange(new string[] { });
		
		PrivateDependencyModuleNames.AddRange(new string[] { });
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "SlateCore", "Slate", "UMG", "InputCore",
			"EnhancedInput", "DeveloperSettings"
		});
	}
}