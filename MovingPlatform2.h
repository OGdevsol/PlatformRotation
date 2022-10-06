// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform2.generated.h"

UCLASS()
class NEWMOVINGASSAULT_API AMovingPlatform2 : public AActor //The header file is for declaring different properties
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//UPROPERTY(EditAnywhere)
	//FVector CubePosition;
private:

	UPROPERTY(EditAnywhere, Category="Moving ")
	FVector PlatformVelocity ;
	UPROPERTY(EditAnywhere, Category="Moving ")
	float MoveDistance=100;
	UPROPERTY(EditAnywhere, Category="Rotating")
	FRotator RotationVelocity;
	UPROPERTY(EditAnywhere, Category="Test")
	FVector TestVector;
    FVector StartLocation;
	void MovePlatform(float DeltaTime);
	bool ShouldReturn();
	void Return();
	void RotatePlatform(float DeltaTime);
	
};
