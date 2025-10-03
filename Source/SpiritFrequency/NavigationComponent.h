
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

	// Längden på raycast
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	float TraceDistance = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

private:
	UPROPERTY(EditAnywhere)
	ACharacter* OwnerCharacter;

	// Helper för att köra raycast i en riktning
	bool SenseDirection(FVector Direction, FHitResult& OutHit, float& OutDistance);

	// 4 raycasts
	void SenseSurroundings();
};
