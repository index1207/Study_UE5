// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeUpdateAnimation(float) override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PlayerState, meta = (AllowPrivateAccess = "true"))
	float Direction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PlayerState, meta=(AllowPrivateAccess="true"))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PlayerState, meta = (AllowPrivateAccess = "true"))
	bool IsJumping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PlayerState, meta = (AllowPrivateAccess = "true"))
	bool IsCrouching;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PlayerState, meta = (AllowPrivateAccess = "true"))
	bool IsDownFireButton;
};
