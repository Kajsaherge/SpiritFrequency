// Fill out your copyright notice in the Description page of Project Settings.


#include "Ghost.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "GhostManager.h"

// Sets default values
AGhost::AGhost()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Skapa audio component
	GhostAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("GhostAudioComponent"));
	GhostAudioComponent->SetupAttachment(RootComponent);
	GhostAudioComponent->bAutoActivate = false; // startar inte automatiskt
	GhostAudioComponent->bIsUISound = false;
	GhostAudioComponent->bAllowSpatialization = true; // 3D-ljud


}



// Called when the game starts or when spawned
void AGhost::BeginPlay()
{
	Super::BeginPlay();

	// Hämta spelaren
	for (TActorIterator<ASpiritFrequencyCharacter> It(GetWorld()); It; ++It)
	{
		TargetPlayer = *It;
		break;
	}

	// Hämta GhostManager
	for (TActorIterator<AGhostManager> It(GetWorld()); It; ++It)
	{
		GhostManager = *It;
		break;
	}

	// Starta ghost-ljud
	if (GhostAudioComponent && GhostSound)
	{
		GhostAudioComponent->SetSound(GhostSound);
		GhostAudioComponent->Play();
	}
}



// Called every frame
void AGhost::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Om ghosten redan attackerar eller ska despawn, gör ingenting
    if (CurrentState == EGhostState::Despawned || CurrentState == EGhostState::Attacking)
    {
        if (GhostAudioComponent && GhostAudioComponent->IsPlaying() && GhostAudioComponent->Sound == MovingSound)
        {
            GhostAudioComponent->Stop(); // stoppa moving sound
        }
        return;
    }

    if (!TargetPlayer)
    {
        if (GhostAudioComponent && GhostAudioComponent->IsPlaying() && GhostAudioComponent->Sound == MovingSound)
        {
            GhostAudioComponent->Stop();
        }
        return;
    }

    FVector PlayerLoc = TargetPlayer->GetActorLocation();
    float Distance = FVector::Dist(PlayerLoc, GetActorLocation());

    const float AttackRange = 100.f;
    if (Distance <= AttackRange)
    {
        CurrentState = EGhostState::Attacking;
        AttackPlayer();
        if (GhostAudioComponent && GhostAudioComponent->IsPlaying() && GhostAudioComponent->Sound == MovingSound)
        {
            GhostAudioComponent->Stop();
        }
        return; // Stoppa Tick direkt
    }

    const float MoveStartDistance = DetectionRadius * 1.2f;
    if (Distance <= MoveStartDistance)
    {
        // Starta moving sound om den inte redan spelas
        if (GhostAudioComponent && MovingSound && (!GhostAudioComponent->IsPlaying() || GhostAudioComponent->Sound != MovingSound))
        {
            GhostAudioComponent->SetSound(MovingSound);
            GhostAudioComponent->Play();
        }

        FVector Direction = (PlayerLoc - GetActorLocation()).GetSafeNormal();
        float AdjustedMoveSpeed = FMath::Lerp(200.f, MoveSpeed, 1.0f - FMath::Clamp(Distance / MoveStartDistance, 0.f, 1.f));
        SetActorLocation(GetActorLocation() + Direction * AdjustedMoveSpeed * DeltaTime);

        CurrentState = EGhostState::Moving;
    }
    else
    {
        // Om ghosten står still, stoppa moving sound
        if (GhostAudioComponent && GhostAudioComponent->IsPlaying() && GhostAudioComponent->Sound == MovingSound)
        {
            GhostAudioComponent->Stop();
        }

        CurrentState = EGhostState::Idle;
    }
}




void AGhost::AttackPlayer()
{
	if (!TargetPlayer || !GhostManager) return;

	// Skada spelaren
	TargetPlayer->Health -= 1;
	TargetPlayer->CheckHealth();

	// Spela attack-ljud
	if (AttackSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, AttackSound, GetActorLocation());
	}

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
	{
		if (!bHasPlayedFirstAttack && FirstAttackSound)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), FirstAttackSound);
			bHasPlayedFirstAttack = true;
		}
	}, 0.5f, false);
	


	// Informera manageren och markera för destruktion
	if (GhostManager)
	{
		GhostManager->OnGhostAttacked(this);
	}

	// Sätt state till Despawned så Tick inte gör mer efter detta
	CurrentState = EGhostState::Despawned;
}







void AGhost::Caught() const
{
	if (CaptureSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, CaptureSound, GetActorLocation());
	}
	
	for (TActorIterator<AGhostManager> It(GetWorld()); It; ++It)
	{
		It->OnGhostCaught();
		break;
	}
}

