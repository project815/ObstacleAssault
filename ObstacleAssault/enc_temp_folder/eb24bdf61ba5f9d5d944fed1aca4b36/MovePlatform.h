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

	// Called every frame
	virtual void Tick(float DeltaTime) override;	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MoveDistance = 1000.f;

private:
	FVector StartLocation;

	FVector EndLocation;

};
