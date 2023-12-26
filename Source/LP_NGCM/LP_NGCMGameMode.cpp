// Copyright Epic Games, Inc. All Rights Reserved.

#include "LP_NGCMGameMode.h"
#include "LP_NGCMCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALP_NGCMGameMode::ALP_NGCMGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
