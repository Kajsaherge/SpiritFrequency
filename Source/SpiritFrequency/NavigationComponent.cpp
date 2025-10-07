// NavigationSenseComponent.cpp
#include "NavigationComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
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

	const float SoundDistanceThreshold = 300.f; // ljud börjar dämpas
	const float HaptikThreshold = 100.f;       // haptik triggas när man är nära väggen
	FVector Velocity = OwnerCharacter->GetVelocity();
	FVector MovementDir = Velocity.GetSafeNormal();

	auto CheckDirection = [&](FVector Direction, FString DirectionName)
	{
		if (SenseDirection(Direction, Hit, Distance))
		{
			// --- Ljudmodifiering ---
			if (Distance <= SoundDistanceThreshold)
			{
				float AttenuationFactor = FMath::Clamp(Distance / SoundDistanceThreshold, 0.f, 1.f);
				UE_LOG(LogTemp, Log, TEXT("%s: Avstånd = %.1f, ljud dämpningsfaktor = %.2f"), *DirectionName, Distance, AttenuationFactor);
				// TODO: Använd AttenuationFactor på AudioComponent om du vill
			}

			// --- Haptik ---
			if (Distance <= HaptikThreshold)
			{
				UE_LOG(LogTemp, Log, TEXT("%s: Haptik triggas!"), *DirectionName);
				// TODO: Trigga haptik på spelaren
			}

			

			FVector CurrentPos = OwnerCharacter->GetActorLocation();
			FVector LastPos = LastPositions.Contains(DirectionName) ? LastPositions[DirectionName] : CurrentPos;
			FVector MovementTowardWall = CurrentPos - LastPos;

			float Dot = FVector::DotProduct(MovementTowardWall, Direction);

			if (Dot > 0.f) // spelaren rör sig mot väggen
			{
				float CurrentTime = GetWorld()->GetTimeSeconds();
				float* LastTimePtr = LastWallHitTimes.Find(DirectionName);
				float LastTime = LastTimePtr ? *LastTimePtr : 0.f;

				if (Distance <= WallHitDistance && CurrentTime - LastTime >= WallHitCooldown)
				{
					if (WallHitSound && GetWorld())
					{
						UGameplayStatics::PlaySoundAtLocation(
							GetWorld(),
							WallHitSound,
							Hit.ImpactPoint,
							1.f, 1.f, 0.f, WallHitAttenuation
						);

						LastWallHitTimes.Add(DirectionName, CurrentTime);
					}
				}
			}

			// Uppdatera senaste positionen
			LastPositions.Add(DirectionName, CurrentPos);


		}
	};

	// Kolla alla fyra riktningar
	CheckDirection(OwnerCharacter->GetActorForwardVector(), TEXT("Framåt"));
	CheckDirection(-OwnerCharacter->GetActorForwardVector(), TEXT("Bakåt"));
	CheckDirection(OwnerCharacter->GetActorRightVector(), TEXT("Höger"));
	CheckDirection(-OwnerCharacter->GetActorRightVector(), TEXT("Vänster"));
}



