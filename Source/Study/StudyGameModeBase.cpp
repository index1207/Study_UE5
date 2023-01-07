// Copyright Epic Games, Inc. All Rights Reserved.


#include "StudyGameModeBase.h"

AStudyGameModeBase::AStudyGameModeBase()
{
	static const ConstructorHelpers::FClassFinder<APawn> playerPawn(TEXT("/Script/CoreUObject.Class'/Script/Study.MyCharacter'"));
	if (playerPawn.Class != nullptr) {
		DefaultPawnClass = playerPawn.Class;
	}
}
