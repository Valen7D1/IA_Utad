// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "params/params.h"
#include "debug/debugdraw.h"
#include "steering.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//m_steering = new SeekSteering();
	m_steering = new ArriveSteering();
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	m_velocity = FVector(0.f, 0.f, 0.f);

	ReadParams("params.xml", m_params);
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	m_velocity += m_steering->GetSteering(this, m_params) * DeltaTime;;

	if (m_velocity.Length()>200)
	{
		m_velocity.GetClampedToMaxSize(m_params.max_velocity);
	}

	SetActorLocation(m_velocity * DeltaTime + GetActorLocation());

	Super::Tick(DeltaTime);

	DrawDebug();
}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAICharacter::OnClickedLeft(const FVector& mousePosition)
{
	SetActorLocation(mousePosition);
}

void AAICharacter::OnClickedRight(const FVector& mousePosition)
{
	m_params.targetPosition = mousePosition;
}

void AAICharacter::DrawDebug()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%f"), m_velocity.Length()));
	SetCircle(this, TEXT("targetPosition"), m_params.targetPosition, 50.f);
}