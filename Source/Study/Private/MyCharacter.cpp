// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	springArm->SetupAttachment(GetCapsuleComponent());
	camera->SetupAttachment(springArm);

	springArm->TargetArmLength = 350.f;
	springArm->bUsePawnControlRotation = true;
	springArm->bEnableCameraLag = true;
	springArm->SetRelativeRotation(FRotator(-35, 0, 0));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -90.f), FRotator(0.f, -90.f, 0.f));

	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAxis(TEXT("Horizontal"), this, &APlayerCharacter::MoveRight);
	InputComponent->BindAxis(TEXT("Vertical"), this, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

	InputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &APlayerCharacter::DoCrouch);
	InputComponent->BindAction(TEXT("Sprint"), IE_Pressed, this, &APlayerCharacter::BeginSprint);
	InputComponent->BindAction(TEXT("Sprint"), IE_Released, this, &APlayerCharacter::EndSprint);
}

void APlayerCharacter::MoveForward(float value)
{
	if (Controller != nullptr && value != 0) {
		const auto Rotation = Controller->GetControlRotation();
		const auto YawRotation = FRotator{ 0, Rotation.Yaw, 0 };

		const auto Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void APlayerCharacter::MoveRight(float value)
{
	if (Controller != nullptr && value != 0) {
		const auto Rotation = Controller->GetControlRotation();
		const auto YawRotation = FRotator{ 0, Rotation.Yaw, 0 };

		const auto Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

void APlayerCharacter::DoCrouch()
{
	if (bIsCrouched) {
		UnCrouch();
	}
	else {
		Crouch();
	}
}

void APlayerCharacter::BeginSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 1000.f;
}

void APlayerCharacter::EndSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

