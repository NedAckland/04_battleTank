// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

protected:
	//how close can ai tank get 
	UPROPERTY(EditDefaultsOnly, Category = "Setup")// consider 
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
