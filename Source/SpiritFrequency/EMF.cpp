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
	UE_LOG(LogTemp, Log, TEXT("EMF %s"), bEMFActive ? TEXT("Activated") : TEXT("Deactivated"));
}

void UEMFComponent::UpdateEMF()
{
	if (!GetOwner()) return;

	FVector PlayerLocation = GetOwner()->GetActorLocation();

	// Hitta alla spöken i världen (kan ersättas med en specifik lista eller interface)
	TArray<AActor*> Ghosts;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Ghost"), Ghosts);

	for (AActor* Ghost : Ghosts)
	{
		if (!Ghost) continue;

		FVector GhostLocation = Ghost->GetActorLocation();
		float Distance = FVector::Dist(PlayerLocation, GhostLocation);

		// ignorera spöken som är för långt bort??
		if (Distance > 3000.f) continue;

		// --- Ping logik ---
		//Kommer säkert finliras sen när ljud läggs in
		float PingRate = FMath::Clamp(1.f / (Distance / 500.f), 0.2f, 5.f); // ju närmare, desto högre frekvens
		UE_LOG(LogTemp, Log, TEXT("Ghost '%s' Distance: %.0f, PingRate: %.2f"), *Ghost->GetName(), Distance, PingRate);

		// --- LJUD implementation
		

		
		// --- Debug ---
		DrawDebugLine(GetWorld(), PlayerLocation, GhostLocation, FColor::Purple, false, 0.1f, 0, 2.f);
		DrawDebugSphere(GetWorld(), GhostLocation, 20.f, 12, FColor::Purple, false, 0.1f);
	}
}
