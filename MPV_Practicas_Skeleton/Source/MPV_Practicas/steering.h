// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "params/params.h"

class AAICharacter;

class MPV_PRACTICAS_API steering
{
public:
	virtual FVector GetSteering(AAICharacter* player, Params playerParams) = 0;
};


class SeekSteering : public steering
{
public:
	virtual FVector GetSteering(AAICharacter* player, Params playerParams) override;
	void DrawDebug(AAICharacter* player, FVector desiredVelocity, FVector acceleration);
};


class ArriveSteering : public steering
{
public:
	virtual FVector GetSteering(AAICharacter* player, Params playerParams) override;
	void DrawDebug(AAICharacter* player, FVector desiredVelocity, FVector acceleration);
};

class AllignSteering : public steering
{
public:
	// will only rotate on Y axis but we leave the rest values there for simplification
	virtual FVector GetSteering(AAICharacter* player, Params playerParams) override;
};
