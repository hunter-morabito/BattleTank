// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank * GetControlledTank() const;
	
	// virtual signature means that the method can be overrode by children!
	// dont need to add overrider to signature in .cpp class
	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;

	// Start the Tank moving the barrel so that a shot would hit where 
	// their crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;
};
