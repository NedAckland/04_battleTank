// Copyright Foxwoods studio's

#pragma once

#include "Public/UObject/Class.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"//put new includes above

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
	// Sets default values for this pawn's properties
	ATank();
};
