// EMFComponent.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "EMF.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPIRITFREQUENCY_API UEMFComponent : public UActorComponent
{
	GENERATED_BODY()

public:    
	UEMFComponent();

protected:
	virtual void BeginPlay() override;

public:    
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Om mätaren är aktiv */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bEMFActive;


	/** Toggle-funktion som binder till knapp */
	UFUNCTION(BlueprintCallable)
	void ToggleEMF();

private:
	void UpdateEMF();

	//LJUD FÖR EMF
	UPROPERTY()
	UAudioComponent* PingAudioComponent;

	UPROPERTY(EditAnywhere, Category="EMF")
	USoundBase* PingSound; // Lägg till i Blueprint för att välja ljudfil

	UPROPERTY(EditAnywhere, Category="EMF")
	float MinPingInterval = 0.05f; // Långsammare ping när långt bort

	UPROPERTY(EditAnywhere, Category="EMF")
	float MaxPingInterval = 5.0f; // Max tid mellan ping

	float TimeSinceLastPing = 0.f;
};
