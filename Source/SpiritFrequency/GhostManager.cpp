#include "GhostManager.h"
#include "Ghost.h"
#include "SpawnPoints.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGhostManager::AGhostManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGhostManager::BeginPlay()
{
    Super::BeginPlay();

    // Hämta spelaren
    for (TActorIterator<ASpiritFrequencyCharacter> It(GetWorld()); It; ++It)
    {
        TargetPlayer = *It;
        break;
    }

    // Hämta alla spawnpoints
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPoints::StaticClass(), SpawnPoints);
    AvailableSpawnPoints = SpawnPoints;

    // Spawn första ghost
    SpawnGhost();
}

void AGhostManager::SpawnGhost()
{
    if (!GhostClass) return;

    // Återställ spawnpoints om alla har används
    if (AvailableSpawnPoints.Num() == 0)
    {
        AvailableSpawnPoints = SpawnPoints;
    }

    if (AvailableSpawnPoints.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("SpawnGhost: inga spawnpoints definierade!"));
        return;
    }

    // Välj slumpmässig spawnpoint
    int32 RandomIndex = FMath::RandRange(0, AvailableSpawnPoints.Num() - 1);
    AActor* ChosenPoint = AvailableSpawnPoints[RandomIndex];
    AvailableSpawnPoints.RemoveAt(RandomIndex);

    // Spawn ghost
    FActorSpawnParameters SpawnParams;
    CurrentGhost = GetWorld()->SpawnActor<AGhost>(GhostClass, ChosenPoint->GetActorLocation(), ChosenPoint->GetActorRotation(), SpawnParams);

    if (!CurrentGhost)
    {
        UE_LOG(LogTemp, Warning, TEXT("SpawnGhost: failed to spawn ghost!"));
        return;
    }

    // Koppla ghosten till manager
    CurrentGhost->GhostManager = this;

    UE_LOG(LogTemp, Warning, TEXT("Spawned Ghost at %s"), *ChosenPoint->GetName());
}

void AGhostManager::OnGhostCaught()
{
    if (!CurrentGhost) return;

    // Destroy ghost
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

void AGhostManager::OnGhostAttacked(AGhost* AttackedGhost)
{
    if (!AttackedGhost) return;

    if (CurrentGhost == AttackedGhost)
        CurrentGhost = nullptr;

    // Destroy ghost
    AttackedGhost->Destroy();

    // Spawn nytt ghost efter liten delay
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
    {
        SpawnGhost();
    }, 0.1f, false);
}

// Called every frame
void AGhostManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
