// Fill out your copyright notice in the Description page of Project Settings.


#include "steering.h"
#include "params/params.h"
#include "debug/debugdraw.h"
#include "AICharacter.h"
#include "util.h"


/////////////////////////// SEEK STEERING ///////////////////////////////////////////////////////

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


/////////////////////////// ARRIVE STEERING /////////////////////////////////////////////////////

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


/////////////////////////// ALLIGN STEERING /////////////////////////////////////////////////////

FVector AllignSteering::GetSteering(AAICharacter* player, Params playerParams)
{

	float desiredAngularVelocity = convertTo180(playerParams.targetRotation - player->current_angle);

	float velocityModifier = 1;
	if (fabs(desiredAngularVelocity) < playerParams.angular_arrive_radius)
	{
		velocityModifier = fabs(desiredAngularVelocity / playerParams.angular_arrive_radius);
	}
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("[%f, %f]"), fabs(desiredAngularVelocity), velocityModifier));
	desiredAngularVelocity *= velocityModifier;

	float newAcceleration = convertTo180(desiredAngularVelocity - player->m_angularVelocity);
	newAcceleration *= playerParams.max_acceleration;

	if (newAcceleration > playerParams.max_angular_acceleration) { newAcceleration = playerParams.max_angular_acceleration; }
	if (newAcceleration < -playerParams.max_angular_acceleration) { newAcceleration = -playerParams.max_angular_acceleration; }

	return FVector(newAcceleration, 0.f, 0.f);
}

