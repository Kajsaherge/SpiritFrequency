#include "EMF.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

UEMFComponent::UEMFComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bEMFActive = false;
}

void UEMFComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UEMFComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (bEMFActive)
    {
        UpdateEMF();
    }
}

void UEMFComponent::ToggleEMF()
{
    bEMFActive = !bEMFActive;

    AActor* Owner = GetOwner();
    if (!Owner) return;

    FVector PlayerLocation = Owner->GetActorLocation();
    FRotator PlayerRotation = Owner->GetActorRotation();

    // Lokala vektorer
    FVector RightVector = PlayerRotation.RotateVector(FVector(0, 1, 0)); // höger
    FVector DownVector = FVector(0, 0, -1);                               // ner
    FVector ForwardVector = PlayerRotation.RotateVector(FVector(1, 0, 0)); // framåt, om du vill

    // Offset för fickan: lite åt höger och ner
    FVector PocketOffset = RightVector * 50.f + DownVector * 300.f;
    FVector PocketLocation = PlayerLocation + PocketOffset;

    if (bEMFActive)
    {
        UE_LOG(LogTemp, Log, TEXT("EMF Activated"));

        if (TakeoutPocket)
        {
            UGameplayStatics::PlaySoundAtLocation(
                GetWorld(),
                TakeoutPocket,      // Sound Cue eller Wave
                PocketLocation,
                0.7f,               // Volume
                1.f
            );
        }

        FTimerHandle EMFStartDelay;
        GetWorld()->GetTimerManager().SetTimer(EMFStartDelay, [this]()
        {
            if (bEMFActive)
            {
                TimeSinceLastPing = 0.f;
                UE_LOG(LogTemp, Log, TEXT("EMF Ping system ready!"));
            }
        }, 0.8f, false);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("EMF Deactivated"));

        if (PutInPocket)
        {
            UGameplayStatics::PlaySoundAtLocation(
                GetWorld(),
                PutInPocket,        // Sound Cue eller Wave
                PocketLocation,
                0.7f,
                1.f
            );
        }
    }
}



void UEMFComponent::UpdateEMF()
{
    if (!GetOwner() || !PingSound) return;

    FVector PlayerLocation = GetOwner()->GetActorLocation();

    // Hitta alla spöken
    TArray<AActor*> Ghosts;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Ghost"), Ghosts);
    if (Ghosts.Num() == 0) return;

    // Närmaste spöke
    AActor* ClosestGhost = nullptr;
    float ClosestDistance = FLT_MAX;

    for (AActor* Ghost : Ghosts)
    {
        if (!Ghost) continue;

        // --- NYTT: filtrera bort ghostar som är hidden / despawned ---
        if (Ghost->IsHidden()) continue;

        float Distance = FVector::Dist(PlayerLocation, Ghost->GetActorLocation());
        if (Distance < ClosestDistance)
        {
            ClosestDistance = Distance;
            ClosestGhost = Ghost;
        }

        DrawDebugLine(GetWorld(), PlayerLocation, Ghost->GetActorLocation(), FColor::Purple, false, 0.1f, 0, 2.f);
        DrawDebugSphere(GetWorld(), Ghost->GetActorLocation(), 20.f, 12, FColor::Purple, false, 0.1f);
    }

    if (!ClosestGhost) return;

    // --- Ping-logik ---
    float MaxEffectDistance = 7000.f;
    float MinEffectDistance = 1500.f;
    float ClampedDistance = FMath::Clamp(ClosestDistance, MinEffectDistance, MaxEffectDistance);
    float NormalizedDistance = 1.f - ((ClampedDistance - MinEffectDistance) / (MaxEffectDistance - MinEffectDistance));
    float AdjustedDistance = FMath::Pow(NormalizedDistance, 2.5f);
    AdjustedDistance = FMath::Clamp(AdjustedDistance, 0.f, 1.f);
    float Interval = FMath::Lerp(MaxPingInterval, MinPingInterval, AdjustedDistance);

    TimeSinceLastPing += GetWorld()->GetDeltaSeconds();

    if (TimeSinceLastPing >= Interval)
    {
        FVector DirectionToGhost = (ClosestGhost->GetActorLocation() - PlayerLocation).GetSafeNormal();

        // Ping-placering relativt spelaren
        FVector RelativePingLocation = DirectionToGhost * 10 + FVector(0, 0, 50.f);

        UGameplayStatics::SpawnSoundAttached(
            PingSound,
            GetOwner()->GetRootComponent(),   // Fäster ljudet till spelaren
            NAME_None,
            RelativePingLocation,             // Offset från root
            EAttachLocation::KeepRelativeOffset,
            true                              // bStopWhenAttachedToDestroyed
        );

        TimeSinceLastPing = 0.f;
    }
}


