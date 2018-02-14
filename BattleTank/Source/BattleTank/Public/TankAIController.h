// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	// Returns a casted Pawn as a Tank which is the possessed Tank	 
	ATank* GetControlledTank() const;

	// Returns the player controlled tank
	ATank* GetPlayerTank() const;

	void BeginPlay() override;


};
