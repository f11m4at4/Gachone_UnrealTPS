// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealTPSGameMode.h"
#include "UnrealTPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealTPSGameMode::AUnrealTPSGameMode()
{

	

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
