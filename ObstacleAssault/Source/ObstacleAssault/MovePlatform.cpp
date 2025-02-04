// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform.h"

// Sets default values
AMovePlatform::AMovePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Move platform forwards
		// Get current location
	FVector currentLocation = GetActorLocation();
		// Add vector to tha location
	currentLocation = currentLocation + (PlatformVelocity * DeltaTime);
		// Set the location
	SetActorLocation(currentLocation);
	// Send platform back  if gone too far
		// Check how far we've moved
	float DistanceMoved = FVector::Dist(StartLocation, currentLocation);
		// Reverse direction of motion if gone too far

	if (DistanceMoved > MoveDistance)
	{
		PlatformVelocity = -PlatformVelocity;
		//StartLocation = currentLocation;
	}
	else
	{


	}

}

