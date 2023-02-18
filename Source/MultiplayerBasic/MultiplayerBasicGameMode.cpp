// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerBasicGameMode.h"
#include "MultiplayerBasicCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerBasicGameMode::AMultiplayerBasicGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
