// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks_2.h"


void UTankTracks_2::SetThrottle(float Throttle)
{
	
		//TODO clamp throttle value so player can't speed up tank
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

