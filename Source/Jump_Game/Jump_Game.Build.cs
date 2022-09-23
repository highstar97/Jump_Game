// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Jump_Game : ModuleRules
{
	public Jump_Game(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
