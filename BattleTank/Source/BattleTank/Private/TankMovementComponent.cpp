// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTracks_2.h"

void UTankMovementComponent::Initialise(UTankTracks_2* LeftTrackToSet, UTankTracks_2* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	//auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward: %f"), Throw)

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO prevent doouble spped due to dual controls used
}
