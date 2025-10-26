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

    // Skapa en lista utan den senaste spawnpointen
    TArray<AActor*> FilteredSpawnPoints = AvailableSpawnPoints;
    if (LastUsedSpawnPoint)
    {
        AvailableSpawnPoints = SpawnPoints;
    }

    // Om det finns minst en kvar, välj slumpmässigt
    AActor* ChosenPoint = nullptr;
    if (FilteredSpawnPoints.Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, FilteredSpawnPoints.Num() - 1);
        ChosenPoint = FilteredSpawnPoints[RandomIndex];
    }
    else
    {
        // Om bara den senaste finns kvar, välj den ändå
        ChosenPoint = AvailableSpawnPoints[0];
    }

    // Ta bort från AvailableSpawnPoints så den inte används direkt igen
    AvailableSpawnPoints.Remove(ChosenPoint);

    // Spawn ghost
    FActorSpawnParameters SpawnParams;
    CurrentGhost = GetWorld()->SpawnActor<AGhost>(GhostClass, ChosenPoint->GetActorLocation(), ChosenPoint->GetActorRotation(), SpawnParams);

    if (!CurrentGhost)
    {
        UE_LOG(LogTemp, Warning, TEXT("SpawnGhost: failed to spawn ghost!"));
        return;
    }

    CurrentGhost->GhostManager = this;

    // Spara den som just användes
    LastUsedSpawnPoint = ChosenPoint;

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
        if (TargetPlayer)
        {
            TargetPlayer->PlayWonSound();
        }

        UE_LOG(LogTemp, Warning, TEXT("All ghosts caught, player wins"));
    }
}

void AGhostManager::OnGhostAttacked(AGhost* AttackedGhost)
{
    if (!AttackedGhost) return;

    // Destroy ghost först
    AttackedGhost->Destroy();

    // Säkerställ att CurrentGhost bara nollställs om det är samma ghost
    if (CurrentGhost == AttackedGhost)
    {
        CurrentGhost = nullptr;
    }

    // Spawn nytt ghost efter liten delay på ett säkert sätt
    FTimerHandle TimerHandle;
    FTimerDelegate TimerDel;

    // Använd TWeakObjectPtr så att timern inte kraschar om GhostManager förstörs
    TWeakObjectPtr<AGhostManager> WeakThis(this);
    TimerDel.BindLambda([WeakThis]()
    {
        if (WeakThis.IsValid())
        {
            WeakThis->SpawnGhost();
        }
    });

    GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 0.1f, false);
}


// Called every frame
void AGhostManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
