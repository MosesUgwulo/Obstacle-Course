// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	startPosition = GetActorLocation();
	
	UE_LOG(LogTemp, Display, TEXT("Stuff"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//get current location
	FVector currentLocation = GetActorLocation();
	
	currentLocation += platformVelocity * DeltaTime;
	
	// set the location
	SetActorLocation(currentLocation);

	float distanceMoved = FVector::Dist(startPosition, currentLocation);

	if (distanceMoved > moveDistance)
	{
		FVector vectorDirection = platformVelocity.GetSafeNormal();
		startPosition = startPosition + vectorDirection * moveDistance;
		SetActorLocation(startPosition);
		platformVelocity *= -1;
	}
}

