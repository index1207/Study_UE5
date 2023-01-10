// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "PlayerCharacter.h"

void UMyAnimInstance::NativeUpdateAnimation(float delta)
{
	Super::NativeUpdateAnimation(delta);
	
	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn)) {
		Speed = pawn->GetVelocity().Size();
		Direction = CalculateDirection(pawn->GetVelocity(), pawn->GetActorRotation());

		auto charactor = Cast<APlayerCharacter>(pawn);
		if (charactor) {
			IsJumping = charactor->GetMovementComponent()->IsFalling();
			IsCrouching = charactor->bIsCrouched;
			IsDownFireButton = charactor->bIsDownFireButton;
		}
	}
}
