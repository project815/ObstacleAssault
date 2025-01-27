// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	int32 InputA = 0;

	UPROPERTY(EditAnywhere)
	int32 InputB = 0;

	UPROPERTY(EditAnywhere)
	int32 ApulsB = 0;

	UPROPERTY(EditAnywhere)
	float MyFloat = 0.00001f;

	UPROPERTY(EditAnywhere)
	bool MyBoolt = true;

	UPROPERTY(EditAnywhere)
	FVector MyVector = FVector();

	UPROPERTY(EditAnywhere)
	float MyX = 30.f;

	
};
