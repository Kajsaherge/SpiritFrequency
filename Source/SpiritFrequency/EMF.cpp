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
	FVector Down = FVector(0,0,-1); // nedåt

	if (bEMFActive)
	{
		UE_LOG(LogTemp, Log, TEXT("EMF Activated"));

		// Ljud för att ta fram EMF (lite nedåt, som ur ficka)
		if (TakeoutPocket)
		{
			FVector PocketLocation = PlayerLocation + Down * 300.f;
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				TakeoutPocket,
				PocketLocation,
				0.5f,               // Volume
				1.f,               // Pitch
				0.f,               // Start time
				PingAttenuation    // <- Använd samma attenuation
			);
		}

		// Starta ping-systemet efter delay
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

		// Ljud för att lägga tillbaka EMF (lite nedåt)
		if (PutInPocket)
		{
			FVector PocketLocation = PlayerLocation + Down * 300.f;
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				PutInPocket,
				PocketLocation,
				0.5f,               // Volume
				1.f,               // Pitch
				0.f,               // Start time
				PingAttenuation    // <- Samma här
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

	if (!ClosestGhost) return;

	// --- Ping-logik ---
	float MaxEffectDistance = 5000.f;
	float MinEffectDistance = 1000.f;
	float ClampedDistance = FMath::Clamp(ClosestDistance, MinEffectDistance, MaxEffectDistance);
	float NormalizedDistance = 1.f - ((ClampedDistance - MinEffectDistance) / (MaxEffectDistance - MinEffectDistance));
	float AdjustedDistance = FMath::Pow(NormalizedDistance, 2.5f);
	AdjustedDistance = FMath::Clamp(AdjustedDistance, 0.f, 1.f);
	float Interval = FMath::Lerp(MaxPingInterval, MinPingInterval, AdjustedDistance);

	TimeSinceLastPing += GetWorld()->GetDeltaSeconds();

	if (TimeSinceLastPing >= Interval)
	{
		// Placera pingen framför spelaren (ungefär där EMF hålls)
		FRotator PlayerRotation = GetOwner()->GetActorRotation();
		FVector Forward = PlayerRotation.Vector();
		FVector PingLocation = PlayerLocation + Forward * 3000.f + FVector(0,0,20.f);

		if (PingSound && PingAttenuation)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				PingSound,
				PingLocation,
				1.f,              // Volume
				1.f,              // Pitch
				0.f,              // Start time
				PingAttenuation   // 3D-attenuation
			);
		}

		TimeSinceLastPing = 0.f;

		UE_LOG(LogTemp, Log, TEXT("Ping! Closest distance: %.1f, Interval: %.2f"), ClosestDistance, Interval);
	}
}
