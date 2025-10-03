// NavigationSenseComponent.cpp
#include "NavigationComponent.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"

UNavigationComponent::UNavigationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UNavigationComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	
}

void UNavigationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SenseSurroundings();
}

bool UNavigationComponent::SenseDirection(FVector Direction, FHitResult& OutHit, float& OutDistance)
{
	if (!OwnerCharacter) return false;

	FVector Start = OwnerCharacter->GetActorLocation() + FVector(0,0,50.f); 
	FVector End = Start + Direction * TraceDistance;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwnerCharacter);

	bool bHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, TraceChannel, Params);

	if (bHit)
	{
		OutDistance = FVector::Distance(Start, OutHit.ImpactPoint);

		// Debug
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 0.1f, 0, 2.0f);
		DrawDebugPoint(GetWorld(), OutHit.ImpactPoint, 10.f, FColor::Yellow, false, 0.1f);
	}
	else
	{
		OutDistance = TraceDistance;
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 2.0f);
	}

	return bHit;
}

void UNavigationComponent::SenseSurroundings()
{
	if (!OwnerCharacter) return;

	FHitResult Hit;
	float Distance;

	// Framåt
	if (SenseDirection(OwnerCharacter->GetActorForwardVector(), Hit, Distance))
	{
		// TODO: Mappa Distance till ljud/haptik (ex: ju kortare desto starkare vibration)
	}

	// Bakåt
	if (SenseDirection(-OwnerCharacter->GetActorForwardVector(), Hit, Distance))
	{
		// TODO
	}

	// Höger
	if (SenseDirection(OwnerCharacter->GetActorRightVector(), Hit, Distance))
	{
		// TODO
	}

	// Vänster
	if (SenseDirection(-OwnerCharacter->GetActorRightVector(), Hit, Distance))
	{
		// TODO
	}
}
