// EMFComponent.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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
};
