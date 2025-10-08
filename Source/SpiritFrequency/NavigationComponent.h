#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NavigationComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPIRITFREQUENCY_API UNavigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UNavigationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	float TraceDistance = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio")
	UAudioComponent* AudioComponent;

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundBase* WallHitSound;

	UPROPERTY(EditAnywhere, Category="Audio")
	USoundAttenuation* WallHitAttenuation;

	UPROPERTY(EditAnywhere, Category="Audio")
	float WallHitDistance = 10.f;

	UPROPERTY(EditAnywhere, Category="Audio")
	float WallHitCooldown = 0.3f;

private:
	UPROPERTY(EditAnywhere)
	ACharacter* OwnerCharacter;

	bool SenseDirection(FVector Direction, FHitResult& OutHit, float& OutDistance);
	void SenseSurroundings();

	// Senaste tid ljudet spelades per riktning
	TMap<FString, float> LastWallHitTimes;

	// För att mäta rörelse mot väggen
	TMap<FString, FVector> LastPositions;

};
