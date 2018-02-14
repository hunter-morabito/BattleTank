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

	// Aim towards Crosshair
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }

	// Get world location if linetrace through crosshair
	//If it hits the landscape
		// Tell controlled tank to aim at this point
}


