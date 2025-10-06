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

	if (!PingAudioComponent)
	{
		AActor* Owner = GetOwner();
		if (Owner)
		{
			PingAudioComponent = NewObject<UAudioComponent>(Owner);
			if (PingAudioComponent)
			{
				PingAudioComponent->bAutoActivate = false;
				PingAudioComponent->RegisterComponent();
				PingAudioComponent->AttachToComponent(Owner->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
			}
		}
	}
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
	UE_LOG(LogTemp, Log, TEXT("EMF %s"), bEMFActive ? TEXT("Activated") : TEXT("Deactivated"));
}

void UEMFComponent::UpdateEMF()
{
    if (!GetOwner() || !PingSound) return;

    FVector PlayerLocation = GetOwner()->GetActorLocation();

    // Hitta alla spöken med tag "Ghost"
    TArray<AActor*> Ghosts;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Ghost"), Ghosts);

    if (Ghosts.Num() == 0)
        return; // Inga spöken i världen

    // Hitta närmaste spöke
    AActor* ClosestGhost = nullptr;
    float ClosestDistance = FLT_MAX;

    for (AActor* Ghost : Ghosts)
    {
        if (!Ghost) continue;

        float Distance = FVector::Dist(PlayerLocation, Ghost->GetActorLocation());
        if (Distance < ClosestDistance)
        {
            ClosestDistance = Distance;
            ClosestGhost = Ghost;
        }

        // Debug
        DrawDebugLine(GetWorld(), PlayerLocation, Ghost->GetActorLocation(), FColor::Purple, false, 0.1f, 0, 2.f);
        DrawDebugSphere(GetWorld(), Ghost->GetActorLocation(), 20.f, 12, FColor::Purple, false, 0.1f);
    }

    if (!ClosestGhost || !PingAudioComponent)
        return;

    // --- Ping-logik ---
	// Maxavstånd för full effekt
	float MaxEffectDistance = 5000.f;

	// Minimum “area” runt spöket innan ping exploderar
	float MinEffectDistance = 1000.f;

	// Clamp avståndet till intervallet [MinEffectDistance, MaxEffectDistance]
	float ClampedDistance = FMath::Clamp(ClosestDistance, MinEffectDistance, MaxEffectDistance);

	// Normalisera avstånd: 0 = längst bort, 1 = innerst vid MinEffectDistance
	float NormalizedDistance = 1.f - ((ClampedDistance - MinEffectDistance) / (MaxEffectDistance - MinEffectDistance));

	// Icke-linjär kurva för dramatisk skillnad
	float AdjustedDistance = FMath::Pow(NormalizedDistance, 2.5f);
	AdjustedDistance = FMath::Clamp(AdjustedDistance, 0.f, 1.f);

	// Beräkna intervallet mellan ping
	float Interval = FMath::Lerp(MaxPingInterval, MinPingInterval, AdjustedDistance);


    TimeSinceLastPing += GetWorld()->GetDeltaSeconds();

    // Debug-loggar
    UE_LOG(LogTemp, Warning, TEXT("ClosestDistance: %.1f, Normalized: %.3f, Adjusted: %.3f, Interval: %.2f"),
        ClosestDistance, NormalizedDistance, AdjustedDistance, Interval);

    if (TimeSinceLastPing >= Interval)
    {
        PingAudioComponent->SetSound(PingSound);
        PingAudioComponent->SetPitchMultiplier(1.0f);
        PingAudioComponent->Play();

        TimeSinceLastPing = 0.f;

        UE_LOG(LogTemp, Log, TEXT("Ping! Closest distance: %.1f, Interval: %.2f"), ClosestDistance, Interval);
    }
}




