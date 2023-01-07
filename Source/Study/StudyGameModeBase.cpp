// Copyright Epic Games, Inc. All Rights Reserved.


#include "StudyGameModeBase.h"

AStudyGameModeBase::AStudyGameModeBase()
{
	static const ConstructorHelpers::FClassFinder<APawn> playerPawn(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_PlayerCharacter.BP_PlayerCharacter_C'"));
	if (playerPawn.Class != nullptr) {
		DefaultPawnClass = playerPawn.Class;
	}
}
