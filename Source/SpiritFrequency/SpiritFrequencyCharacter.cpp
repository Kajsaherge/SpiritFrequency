// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpiritFrequencyCharacter.h"
#include "SpiritFrequencyPlayerController.h"
#include "EngineUtils.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "Ghost.h"
#include "Kismet/GameplayStatics.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpiritFrequency.h"

ASpiritFrequencyCharacter::ASpiritFrequencyCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	// Create the first person mesh that will be viewed only by this character's owner
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));

	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	// Create the Camera Component	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(FirstPersonMesh, FName("head"));
	FirstPersonCameraComponent->SetRelativeLocationAndRotation(FVector(-2.8f, 5.89f, 0.0f), FRotator(0.0f, 90.0f, -90.0f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bEnableFirstPersonFieldOfView = true;
	FirstPersonCameraComponent->bEnableFirstPersonScale = true;
	FirstPersonCameraComponent->FirstPersonFieldOfView = 70.0f;
	FirstPersonCameraComponent->FirstPersonScale = 0.6f;

	// configure the character comps
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;

	//KOMPONENTER
	NavigationComponent = CreateDefaultSubobject<UNavigationComponent>(TEXT("NavigationComponent"));
	EMFComponent = CreateDefaultSubobject<UEMFComponent>(TEXT("EMFComponent"));
}

void ASpiritFrequencyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{  

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpiritFrequencyCharacter::MoveInput);

		EnhancedInputComponent->BindAction(EMFToggleAction, ETriggerEvent::Started, this, &ASpiritFrequencyCharacter::ToggleEMF);
		
		EnhancedInputComponent->BindAction(CatchGhostAction, ETriggerEvent::Started, this, &ASpiritFrequencyCharacter::CatchGhost);
	}
	else
	{
		UE_LOG(LogSpiritFrequency, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ASpiritFrequencyCharacter::TryCatchGhost() const
{

	ASpiritFrequencyPlayerController* MyPC = Cast<ASpiritFrequencyPlayerController>(GetController());
	if (MyPC && MyPC->bIsMenuOpen)
	{
		return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("TryCatchGhost() triggered"));
	
	FVector PlayerLoc = GetActorLocation();
	AGhost* ClosestGhost = nullptr;
	float ClosestDist = CatchRadius;

	for (TActorIterator<AGhost> It(GetWorld()); It; ++It)
	{
		AGhost* Ghost = *It;
		float Distance = FVector::Dist(PlayerLoc, Ghost->GetActorLocation());
		
		if (Distance <= CatchRadius && Distance < ClosestDist)
		{
			ClosestGhost = Ghost;
			ClosestDist = Distance;
		}
	}

	if (ClosestGhost)
	{
		ClosestGhost->Caught();

		UE_LOG(LogTemp, Warning, TEXT("Ghost caught!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No ghost nearby."));
	}
}


void ASpiritFrequencyCharacter::MoveInput(const FInputActionValue& Value)
{

	ASpiritFrequencyPlayerController* MyPC = Cast<ASpiritFrequencyPlayerController>(GetController());
	if (MyPC && MyPC->bIsMenuOpen)
	{
		return;
	}
	// get the Vector2D move axis
	FVector2D MovementVector = Value.Get<FVector2D>();

	// pass the axis values to the move input
	DoMove(MovementVector.X, MovementVector.Y);

}

void ASpiritFrequencyCharacter::DoMove(float Right, float Forward)
{

	ASpiritFrequencyPlayerController* MyPC = Cast<ASpiritFrequencyPlayerController>(GetController());
	if (MyPC && MyPC->bIsMenuOpen)
	{
		return;
	}
	
	if (GetController())
	{
		// pass the move inputs
		AddMovementInput(GetActorRightVector(), Right);
		AddMovementInput(GetActorForwardVector(), Forward);
	}
}


void ASpiritFrequencyCharacter::ToggleEMF()
{

	ASpiritFrequencyPlayerController* MyPC = Cast<ASpiritFrequencyPlayerController>(GetController());
	if (MyPC && MyPC->bIsMenuOpen)
	{
		return;
	}
	
	if (EMFComponent)
	{
		EMFComponent->ToggleEMF();
	}
}

void ASpiritFrequencyCharacter::CatchGhost()
{

	ASpiritFrequencyPlayerController* MyPC = Cast<ASpiritFrequencyPlayerController>(GetController());
	if (MyPC && MyPC->bIsMenuOpen)
	{
		return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("CatchGhost() triggered"));
	TryCatchGhost();
}

void ASpiritFrequencyCharacter::CheckHealth()
{
	if (Health <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player has died!"));

		// Restart level
		UWorld* World = GetWorld();
		if (World)
		{
			FName CurrentLevel = *World->GetMapName();
			UGameplayStatics::OpenLevel(World, CurrentLevel);
		}
	}
}

