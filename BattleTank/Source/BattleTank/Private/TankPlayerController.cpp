// Copyright Foxwoods studio's

#include "Public/TankPlayerController.h"
#include "Classes/Engine/World.h"
#include "TankAimingComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetPawn()) { return; } // if not possesing
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);

	}
}

void  ATankPlayerController::OnPossessedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("recived"));
}


void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation; // OUT Parameter
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	//UE_LOG(LogTemp, Warning, TEXT ("bGotHitLocation: %i"), bGotHitLocation)
	if (bGotHitLocation) // has "side effect", is going to line trace
	{
		AimingComponent->AimAt(HitLocation);
	}
}

//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find crosshair position in pixal co-ordinates
	int ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// de-project screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//line trace along that LookDiretion and see what we hit ( up to max range)
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; // line trace didn't succeed
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;//to be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

