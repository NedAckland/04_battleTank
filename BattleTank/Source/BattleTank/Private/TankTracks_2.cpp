// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks_2.h"


void UTankTracks_2::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s:Throttle : %f"),  *Name, Throttle)

		//TODO clamp throttle value so player can't speed up tank
}

