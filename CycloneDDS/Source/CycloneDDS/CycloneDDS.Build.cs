using System.IO;
using UnrealBuildTool;

public class CycloneDDS : ModuleRules
{
    public CycloneDDS(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Projects" });

        // Setting up the paths based on your directory structure
        string LibrariesPath = Path.Combine(ModuleDirectory, "..", "..", "Binaries", "Win64");

        PublicIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "..", "..", "Source", "CycloneDDS", "Public", "Include")
            }
        );

        PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "ddsc.lib"));

    }
}
