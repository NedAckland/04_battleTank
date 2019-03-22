// Copyright Foxwoods studio's

#include "Tank.h"
#include "GameFramework/Actor.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include"GameFramework/Character.h"

void ATank::BeginPlay()
{
	Super::BeginPlay(); //needed for bp begin play to run!!
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto TankName = GetName();
	///UE_LOG(LogTemp, Warning, TEXT("%S DONKEY: Tank C++ Construct "), *TankName)
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (IsReloaded) 
	{
		//spawn projectile at socket location from barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
	//	Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
