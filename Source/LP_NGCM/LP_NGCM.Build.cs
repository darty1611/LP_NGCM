// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LP_NGCM : ModuleRules
{
	public LP_NGCM(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule" });
	}
}
