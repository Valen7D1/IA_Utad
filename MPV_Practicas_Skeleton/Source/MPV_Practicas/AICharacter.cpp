// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "params/params.h"
#include "debug/debugdraw.h"
#include "steering.h"
#include "util.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//m_steering = new SeekSteering();
	m_steering = new ArriveSteering();
	m_angularSteering = new AllignSteering();
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	m_velocity = FVector(0.f);

	ReadParams("params.xml", m_params);
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	MoveCharacter(DeltaTime);
	RotateCharacter(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("[%f, %f]"),current_angle , m_params.targetRotation));

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

	FVector dir = (mousePosition - GetActorLocation()).GetSafeNormal();
	float angle = FMath::RadiansToDegrees(atan2(dir.Z, dir.X));
	m_params.targetRotation = angle;
}


void AAICharacter::MoveCharacter(float DeltaTime)
{
	m_velocity += m_steering->GetSteering(this, m_params) * DeltaTime;;

	if (m_velocity.Length() > m_params.max_velocity)
	{
		m_velocity.GetClampedToMaxSize(m_params.max_velocity);
	}

	SetActorLocation(m_velocity * DeltaTime + GetActorLocation());
}


void AAICharacter::RotateCharacter(float DeltaTime)
{
	m_angularVelocity += (m_angularSteering->GetSteering(this, m_params) * DeltaTime).X;

	if (m_angularVelocity > m_params.max_angular_velocity) { m_angularVelocity = m_params.max_angular_velocity; }
	if (m_angularVelocity < -m_params.max_angular_velocity) { m_angularVelocity = -m_params.max_angular_velocity; }

	current_angle = convertTo360(m_angularVelocity+current_angle);
	SetActorAngle(current_angle);
}


void AAICharacter::DrawDebug()
{
	TArray<FVector> Points =
	{
		FVector(0.f, 0.f, 0.f),
		FVector(100.f, 0.f, 0.f),
		FVector(100.f, 0.f, 100.f),
		FVector(100.f, 0.f, 100.f),
		FVector(0.f, 0.f, 100.f)
	};

	SetPath(this, TEXT("follow_path"), TEXT("path"), Points, 5.0f, PathMaterial);

	SetCircle(this, TEXT("targetPosition"), m_params.targetPosition, 20.0f);
	FVector dir(cos(FMath::DegreesToRadians(m_params.targetRotation)), 0.0f, sin(FMath::DegreesToRadians(m_params.targetRotation)));
	SetArrow(this, TEXT("targetRotation"), dir, 80.0f);
}


float AAICharacter::GetActorAngle() const
{
	FQuat currQuat = GetActorQuat();
	FVector axis;
	float axisAngle;
	currQuat.ToAxisAndAngle(axis, axisAngle);
	axisAngle = FMath::RadiansToDegrees(axisAngle);
	if (axis.Y > 0.0f)
		axisAngle = -axisAngle;

	axisAngle = convertTo360(axisAngle);
	return axisAngle;
}

void AAICharacter::SetActorAngle(float angle)
{ 
	FRotator newRot(angle, 0.f, 0.f);// = angle.Rotation();
	SetActorRotation(newRot); 
}