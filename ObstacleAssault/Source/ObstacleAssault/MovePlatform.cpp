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

	MyX = MyVector.X;

	//float tmp = MyVector.Y;
	//MyVector.Y = MyVector.Z;
	//MyVector.Z = tmp;



	// 플레이어 캐릭터 가져오기
	//SetActorLocation(MyVector);
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalVector = MyVector;

	LocalVector.Z += 100.f;
	
	MyVector.Y += 1.f;

	SetActorLocation(LocalVector);


	// Move platform forwards
		// Get current location
		// Add vector to tha location
		// Set the location
	// Send platform back  if gone too far
		// Check how far we've moved
		// Reverse direction of motion if gone too far


}

