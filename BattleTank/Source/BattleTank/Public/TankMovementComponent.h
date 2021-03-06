/// Copyright Foxwoods studio's
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks_2;

/**
 * responsible for driving tank tracks
 */


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTracks_2* LeftTrackToSet, UTankTracks_2* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "input")
	void intendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "input")
	void intendTurnRight(float Throw);

private:
	//Talled from the pathfinding logic by the Ai controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:

	UTankTracks_2* LeftTrack = nullptr;
	UTankTracks_2* RightTrack = nullptr;
};
