// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform2.h"

// Sets default values
AMovingPlatform2::AMovingPlatform2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform2::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	 RotatePlatform(DeltaTime);
}
void AMovingPlatform2::MovePlatform(float DeltaTime)
{

	if (ShouldReturn())
	{
		Return();
	}
	else
	{
		FVector currentLocation = GetActorLocation();

		currentLocation = currentLocation + PlatformVelocity * DeltaTime;

		SetActorLocation(currentLocation);
	}
}
bool AMovingPlatform2::ShouldReturn()
{
	float distanceMoved = FVector::Dist(StartLocation, GetActorLocation());
	return distanceMoved > MoveDistance;
}
void AMovingPlatform2::Return()
{
	FVector MoveDirection = PlatformVelocity.GetSafeNormal();
	StartLocation = StartLocation + MoveDirection * MoveDistance;
	SetActorLocation(StartLocation);
	PlatformVelocity = -PlatformVelocity;
}

void AMovingPlatform2::RotatePlatform(float DeltaTime)
{
	
	AddActorLocalRotation(RotationVelocity*DeltaTime);
}
