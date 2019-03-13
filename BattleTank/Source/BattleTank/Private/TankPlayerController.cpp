// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankPlayerController.h"

#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller posessing %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
	///UE_LOG(LogTemp, Warning, TEXT("Player controller Ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
	
	UE_LOG(LogTemp, Warning, TEXT("%s tank"))
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT Parameter
	if (GetSightRayHitLocation(HitLocation)) // has "side efcct", ius going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
			//TODO tell controltank to aim at point
	}
}

//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}