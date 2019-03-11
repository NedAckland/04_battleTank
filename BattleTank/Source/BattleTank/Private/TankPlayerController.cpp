// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankPlayerController.h"

#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"





ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}