// Fill out your copyright notice in the Description page of Project Settings.

#include "MovePlatform.h"
#include "Components/SplineComponent.h"

// Sets default values
AMovePlatform::AMovePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(RootComponent);

	// Optionally, set up default spline points if needed
	SplineComponent->ClearSplinePoints();
	SplineComponent->AddSplinePoint(FVector(0.0f, 0.0f, 0.0f), ESplineCoordinateSpace::Local);
	SplineComponent->AddSplinePoint(FVector(500.0f, 0.0f, 0.0f), ESplineCoordinateSpace::Local);
}

// Called when the game starts or when spawned
void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Move platform forwards
		// Get current location
	//FVector currentLocation = GetActorLocation();
	//	// Add vector to tha location
	//currentLocation = currentLocation + (PlatformVelocity * DeltaTime);
	//	// Set the location
	//SetActorLocation(currentLocation);
	//// Send platform back  if gone too far
	//	// Check how far we've moved
	//float DistanceMoved = FVector::Dist(StartLocation, currentLocation);
	//	// Reverse direction of motion if gone too far

	//if (DistanceMoved > MoveDistance)
	//{
	//	FVector moveDirection = PlatformVelocity.GetSafeNormal();
	//	StartLocation = StartLocation + moveDirection * MoveDistance;
	//	SetActorLocation(StartLocation);
	//	PlatformVelocity = -PlatformVelocity;
	//}
	CurrentDistance += DeltaTime;

	// 스플라인의 전체 길이를 넘어가면 방향 반전
	if (CurrentDistance >= SplineComponent->GetSplineLength())
	{
		CurrentDistance = SplineComponent->GetSplineLength();
	}

	FVector NewLocation = SplineComponent->GetLocationAtDistanceAlongSpline(CurrentDistance, ESplineCoordinateSpace::World);
	SetActorLocation(NewLocation);
}

