// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "params/params.h"
#include "GameFramework/PlayerController.h"


#include "AICharacter.generated.h"


class Steering
{
public:
	virtual FVector GetSteering(AAICharacter* player, Params playerParams) = 0;
};

class SeekSteering : public Steering
{
public:
	virtual FVector GetSteering(AAICharacter* player, Params playerParams) override;
	void DrawDebug(AAICharacter* player, FVector desiredVelocity, FVector acceleration);
};

UCLASS()
class MPV_PRACTICAS_API AAICharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAICharacter();

	/**  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AIChar)
	uint32 bDoMovement : 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	Params m_params;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "AIFunctions")
	void OnClickedLeft(const FVector& mousePosition);
	UFUNCTION(BlueprintCallable, Category = "AIFunctions")
	void OnClickedRight(const FVector& mousePosition);
	
	const Params& GetParams() const { return m_params; }

	void DrawDebug();

public:
	FVector m_velocity;
	Steering* steering = new SeekSteering();
};

