// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Example : ModuleRules
{
    public Example(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
            { "Core", "CoreUObject", "Engine", "InputCore", "StructUtils" });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
