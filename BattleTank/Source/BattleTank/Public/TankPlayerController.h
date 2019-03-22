// Copyright Foxwoods studio's

#pragma once


#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//last include

class UTankAimingComponent;

/**
 * responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);
	
private:
	virtual void BeginPlay() override;
	// Called every frame

	virtual void Tick(float DeltaTime ) override;

	// start the tank moving the barrel so that a shot will hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	//return out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;


	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& Hitlocation) const;
	
};
