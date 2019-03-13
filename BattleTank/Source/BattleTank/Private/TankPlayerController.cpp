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
	//get world location if linetrace through crosshair
	// if hit landscape
		//tell controltank to aim at point

}