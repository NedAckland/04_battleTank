// Fill out your copyright notice in the Description page of Project Settings.

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

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTracks_2* LeftTrackToSet, UTankTracks_2* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = input)
	void IntendMoveForward(float Throw);



private:

	UTankTracks_2* LeftTrack = nullptr;
	UTankTracks_2* RightTrack = nullptr;
};
