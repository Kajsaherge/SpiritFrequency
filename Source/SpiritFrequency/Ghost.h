// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpiritFrequencyCharacter.h"
#include "Components/AudioComponent.h"
#include "Ghost.generated.h"

class ASpiritFrequencyCharacter;
class AGhostManager;

UENUM(BlueprintType)
enum class EGhostState : uint8
{
	Idle,
	Moving,
	Attacking,
	Despawned
};

UCLASS()
class SPIRITFREQUENCY_API AGhost : public AActor
{
	GENERATED_BODY()

	
	
public:	
	// Sets default values for this actor's properties
	AGhost();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	UPROPERTY()
	UAudioComponent* GhostAudioComponent;

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundBase* GhostSound;

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundBase* MovingSound;

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundBase* CaptureSound;

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundBase* AttackSound;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Caught() const;

	// Radius inom vilket spöket upptäcker spelaren
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ghost")
	float DetectionRadius = 1000.f;

	// Rörelsehastighet mot spelaren
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ghost")
	float MoveSpeed = 600.f; // units per second

	// Referens till spelaren
	UPROPERTY(BlueprintReadOnly)
	ASpiritFrequencyCharacter* TargetPlayer = nullptr;

	UPROPERTY(BlueprintReadOnly)
	AGhostManager* GhostManager;
	

	UPROPERTY(BlueprintReadWrite)
	EGhostState CurrentState;

	

	

private:
	float PulseTimer = 0.f;          
	float CurrentPulseSpeed = 1.0f;

	void AttackPlayer();


};
