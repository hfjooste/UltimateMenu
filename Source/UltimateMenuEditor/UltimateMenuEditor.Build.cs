using UnrealBuildTool;

public class UltimateMenuEditor : ModuleRules
{
	public UltimateMenuEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] { });
		PrivateIncludePaths.AddRange(new string[] { });
		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"UnrealEd"
		});

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"UltimateMenu",
			"AssetTools",
			"DataTableEditor",
		});

		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}