// Fill out your copyright notice in the Description page of Project Settings.


#include "steering.h"
#include "params/params.h"
#include "debug/debugdraw.h"
#include "AICharacter.h"


FVector SeekSteering::GetSteering(AAICharacter* player, Params playerParams)
{
	FVector desiredVelocity = playerParams.targetPosition - player->GetActorLocation();
	desiredVelocity.Normalize();
	desiredVelocity *= playerParams.max_velocity;

	FVector newAcceleration = desiredVelocity - player->m_velocity;
	newAcceleration.Normalize();
	newAcceleration *= playerParams.max_acceleration;

	DrawDebug(player, desiredVelocity, newAcceleration);

	return newAcceleration;
}

void SeekSteering::DrawDebug(AAICharacter* player, FVector desiredVelocity, FVector acceleration)
{
	SetArrow(player, TEXT("linear_velocity"), desiredVelocity, 1000.f);
	SetArrow(player, TEXT("linear_acceleration"), acceleration, 1000.f);
}



FVector ArriveSteering::GetSteering(AAICharacter* player, Params playerParams)
{
	FVector desiredVelocity = playerParams.targetPosition - player->GetActorLocation();

	float velocityModifier = 1;
	if (desiredVelocity.Length() <= playerParams.dest_radius)
	{
		velocityModifier = desiredVelocity.Length() / playerParams.dest_radius;
	}

	desiredVelocity.Normalize();

	// velocity depends of distance to target
	desiredVelocity *= playerParams.max_velocity * velocityModifier;

	FVector newAcceleration = desiredVelocity - player->m_velocity;
	newAcceleration.Normalize();
	newAcceleration *= playerParams.max_acceleration;

	DrawDebug(player, desiredVelocity, newAcceleration);

	return newAcceleration;
}

void ArriveSteering::DrawDebug(AAICharacter* player, FVector desiredVelocity, FVector acceleration)
{
	SetArrow(player, TEXT("linear_velocity"), desiredVelocity, 1000.f);
	SetArrow(player, TEXT("linear_acceleration"), acceleration, 1000.f);
}

