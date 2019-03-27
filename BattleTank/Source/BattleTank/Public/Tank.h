// Copyright Foxwoods studio's

#pragma once

#include "Public/UObject/Class.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"//put new includes above

class Projectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;


private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;


};
