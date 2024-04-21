// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "params/params.h"
#include "debug/debugdraw.h"
#include "steering.h"
#include "util.h"
#include "Kismet/KismetMathLibrary.h"
#include "pathfinding/astar.h"


AAICharacter::AAICharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_steering = new SeekSteering();
	//m_steering = new ArriveSteering();
	m_angularSteering = new AllignSteering();
}


void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	m_velocity = FVector(0.f);

	const FString FilePath = FPaths::ProjectContentDir() + TEXT("Grid.txt");
	Grid = ParseGridDataFromFile(FilePath);

	std::vector<GridLocation> Path = GetPath(Grid, Grid[0][0], Grid[Grid.size()-1][Grid[0].size()-1]);

	for (GridLocation GridLocation: Path)
	{
		m_params.path.Push(GridLocation.Location);
	}

	
	ReadParams("params.xml", m_params);
	//ReadPath("path.xml", m_params);
	ReadObstacles("obstacles.xml", m_params);
}


void AAICharacter::Tick(float DeltaTime)
{
	//CollisionManager(DeltaTime);
	MoveCharacter(DeltaTime);
	RotateCharacter(DeltaTime);
	
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("[%f, %f]"),current_angle , m_params.targetRotation));

	Super::Tick(DeltaTime);

	DrawDebug();
}


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


void AAICharacter::CollisionManager(float DeltaTime)
{
	// first check if its colliding with anything
	FVector Winner = FVector(FLT_MAX);
	float WinnerDist = FLT_MAX;

	FVector ActorLocation = GetActorLocation();
	FVector AheadPosition = m_params.targetPosition - GetActorLocation();
	AheadPosition.Normalize();

	//SetArrow(this, TEXT("linear_velocity"), AheadPosition, 8000.f);
	
	AheadPosition = GetActorLocation() + AheadPosition * m_params.look_ahead;
	
	for (FVector const Obstacle : m_params.obstacles)
	{
		// set values because i use FVector pocho
		FVector ObstacleLocation = Obstacle;
		float ObstacleRadius = Obstacle.Y;
		ObstacleLocation.Y = 0.f;
		
		// if distance of projected location is lower than radius of both obstacle and player
		float const Distance = FVector::Dist(AheadPosition, ObstacleLocation);
		
		if (Distance < (ObstacleRadius + m_radius) && Distance < WinnerDist)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("Distance: %f"), Distance ));
			WinnerDist = Distance;
			Winner = ObstacleLocation;
		}
	}
	
	if (WinnerDist < FLT_MAX)
	{
		FVector RO = Winner - GetActorLocation();
		FVector Diff = AheadPosition - Winner;

		FVector RO_Diff = FVector::CrossProduct(RO, Diff);
		FVector Final = FVector::CrossProduct(RO_Diff, RO);

		Final.Normalize();
		
		m_velocity += Final * m_params.max_acceleration * DeltaTime * 1.3f;
	}
}

void AAICharacter::SelectNextPathPosition(float DeltaTime)
{
	int SegmentId = 0;
	float ClosestDistance = MAX_FLT;
	float TempDistance = MAX_FLT;
	FVector Winner = FVector::Zero();
	FVector WinnerDirection = FVector::Zero();
	
	for (int i = 0; i<m_params.path.Num(); ++i)
	{
		FVector MyLocation = GetActorLocation();
		FVector FirstPoint = m_params.path[i];
		FVector SecondPoint = FVector::Zero();
		if (i + 1 == m_params.path.Num())
		{
			SecondPoint = m_params.path[0];
		}
		else
		{
			SecondPoint = m_params.path[i+1];
		}
		
		FVector SegmentVector = SecondPoint - FirstPoint;
		FVector AP = MyLocation - FirstPoint;
		
		float lengthSqrAB = SegmentVector.X * SegmentVector.X + SegmentVector.Z * SegmentVector.Z;
		float t = (AP.X * SegmentVector.X + AP.Z * SegmentVector.Z) / lengthSqrAB;

		if(t < 0) { t = 0; }
		if(t > 1) { t = 1; }

		FVector Final = FirstPoint + t * SegmentVector;

		if ((TempDistance = FVector::Dist(MyLocation, Final)) < ClosestDistance)
		{
			ClosestDistance = TempDistance;
			SegmentId = i;
			Winner = Final;
			WinnerDirection = SegmentVector;
		}
	}
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("[%f, %f]"), Winner.X, Winner.Z ));
	SetCircle(this, TEXT("targetPosition"), Winner, 20.0f);

	if (SegmentId + 1 == m_params.path.Num())
	{
		m_params.targetPosition = m_params.path[0];
	}
	else
	{
		m_params.targetPosition = m_params.path[SegmentId+1];
	}

	FVector dir = (m_params.targetPosition - GetActorLocation()).GetSafeNormal();
	float angle = FMath::RadiansToDegrees(atan2(dir.Z, dir.X));
	m_params.targetRotation = angle;
	
	// WinnerDirection.Normalize();
	// m_params.targetPosition = Winner + WinnerDirection * m_params.max_velocity * DeltaTime;
	
}

void AAICharacter::MoveCharacter(float DeltaTime)
{

	SelectNextPathPosition(DeltaTime);
	
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


void AAICharacter::DrawDebug() const
{
	TArray<FVector> Points = m_params.path;

	SetPath(this, TEXT("follow_path"), TEXT("path"), m_params.path, 5.0f, PathMaterial);

	// perdon por este draw debug que voy a hacer pero sinceramente la vida es dura
	// TArray<FString> ObstaclesArray; ObstaclesArray.Add(FString("Obstacle1")); ObstaclesArray.Add(FString("Obstacle2"));
	// for (int i = 0; i < m_params.obstacles.Num(); ++i)
	// {
	// 	FVector temp = m_params.obstacles[i];
	// 	float radius = temp.Y;
	// 	temp.Y = 0.f;
	// 	SetCircle(this, ObstaclesArray[i], temp, radius);
	// }
	
	FVector dir(cos(FMath::DegreesToRadians(m_params.targetRotation)), 0.0f, sin(FMath::DegreesToRadians(m_params.targetRotation)));
	//SetArrow(this, TEXT("targetRotation"), dir, 80.0f);

	SetCircle(this, "targetPosition", m_params.targetPosition, 20.f);
	DrawGridDebugCircles(); // pathfinding debug
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

void AAICharacter::DrawGridDebugCircles() const
{
	const float CircleRadius = 20.f; // Adjust this radius according to your needs

	for (int32 RowIndex = 0; RowIndex < Grid.size(); ++RowIndex)
	{
		for (int32 ColIndex = 0; ColIndex < Grid[RowIndex].size(); ++ColIndex)
		{
			const FVector Location = FVector(Grid[RowIndex][ColIndex].Location.X, 0.f, Grid[RowIndex][ColIndex].Location.Z);
			
			// Calculate rotation to align the circle with the X-Z plane
			const FRotator Rotation = FRotator(0.f, 90.f, 0.f);

			// Create transform combining location and rotation
			const FTransform Transform = FTransform(Rotation, Location, FVector::OneVector);
			if (Grid[RowIndex][ColIndex].EntryCost < 0)
			{
				DrawDebugCircle(GetWorld(), Transform.ToMatrixWithScale(), CircleRadius, 32, FColor::Red, false, -1, 0, 5.f);
			}
			else
			{
				DrawDebugCircle(GetWorld(), Transform.ToMatrixWithScale(), CircleRadius, 32, FColor::Green, false, -1, 0, 5.f);
			}
		}
	}
}