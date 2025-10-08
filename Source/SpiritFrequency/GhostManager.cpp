// Fill out your copyright notice in the Description page of Project Settings.


#include "GhostManager.h"
#include "Ghost.h"
#include "SpawnPoints.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGhostManager::AGhostManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGhostManager::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPoints::StaticClass(), SpawnPoints);

	//kopiera till spawnpoit
	AvailableSpawnPoints = SpawnPoints;

	SpawnGhost();
	
}

void AGhostManager::SpawnGhost()
{

	if (!GhostClass) return;

	if (AvailableSpawnPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No more available spawnpoints!"));
		return;
	}

	// Välj slumpmässigt index
	int32 RandomIndex = FMath::RandRange(0, AvailableSpawnPoints.Num() - 1);
	AActor* ChosenPoint = AvailableSpawnPoints[RandomIndex];

	// Ta bort den från listan så den inte används igen
	AvailableSpawnPoints.RemoveAt(RandomIndex);

	FVector SpawnLocation = ChosenPoint->GetActorLocation();
	FRotator SpawnRotation = ChosenPoint->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	CurrentGhost = GetWorld()->SpawnActor<AGhost>(GhostClass, SpawnLocation, SpawnRotation, SpawnParams);

	UE_LOG(LogTemp, Warning, TEXT("Spawned Ghost at %s"), *ChosenPoint->GetName());
}

// Called every frame
void AGhostManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGhostManager::OnGhostCaught()
{
	if (CurrentGhost)
	{
		CurrentGhost->Destroy();
		CurrentGhost = nullptr;
		GhostsCaught++;

		if (GhostsCaught < GhostsToCatch)
		{
			SpawnGhost();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("All ghosts caught, player wins"));
		}
	}
}

