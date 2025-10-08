// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GhostManager.generated.h"

class AGhost; 
class ASpiritFrequencyCharacter; 

UCLASS()
class SPIRITFREQUENCY_API AGhostManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGhostManager();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AGhost> GhostClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float SpawnRadius = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 GhostsToCatch = 5;

	UPROPERTY()
	AGhost* CurrentGhost;

	int32 GhostsCaught = 0;

	void SpawnGhost();
	
	TArray<AActor*> SpawnPoints;
	
	TArray<AActor*> AvailableSpawnPoints;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnGhostCaught();

};
