// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank * GetControlledTank() const;
	
	// virtual signature means that the method can be overrode by children!
	// dont need to add overrider to signature in .cpp class
	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;

	// Start the Tank moving the barrel so that a shot would hit where 
	// their crosshair intersects the world
	void AimTowardsCrosshair();

	// const means that the member variables in the class cannot be changed!
	bool GetSightRayHitLocation(FVector&)const;

	bool GetLookDirection(FVector2D,FVector&) const;

	bool GetLookVectorHitLocation(FVector, FVector&)const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
};
