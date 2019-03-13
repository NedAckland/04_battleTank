// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	// Called every frame

	virtual void Tick(float DeltaTime ) override;

	// start the tank moving the barrel so that a shot will hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	//return out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;


	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	float CrosshairYLocation = 0.3333f;


	
};
