// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Possessed Tank %s"), *(ControlledTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Failed to possess tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter

	if (GetSightRayHitLocation(HitLocation)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		// Get world location if linetrace through crosshair
	
		//If it hits the landscape
			// Tell controlled tank to aim at this point
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {
	HitLocation = FVector(4, 4, 4);
	// get camera position 
	// get dot position
	// ray cast line 
	// get where it hits terrain
	return true;
}


