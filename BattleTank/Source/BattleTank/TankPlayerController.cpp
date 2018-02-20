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
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		// Get world location if linetrace through crosshair
	
		//If it hits the landscape
			// Tell controlled tank to aim at this point
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	// Fills in the viewport (screen) size
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	// Get Screen location of the dot, position is recorded in two spaces, right now its .5 horizontal and .333333 vertical
	FVector2D ScreenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		// Line-trace along that look direction, and see what we hit (up to max range)
		FHitResult LookVectorHitLocation;
		GetLookVectorHitLocation(LookDirection, HitLocation);
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const {

	// "De-project" the screen position of the crosshair to a world direction 
	// Out Params for deprojecting the position on screen
	FVector WorldLocation; // To be discarding 
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection)) // Ignoring WorldLocation because it returns the camera's world location
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
		return true;
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &LookVectorHitLocation) const 
{

	FHitResult HitResult;

	auto StartLocation = PlayerCameraManager->GetCameraLocation();

	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		LookVectorHitLocation = HitResult.Location;
		return true;
	}
	LookVectorHitLocation = FVector(0);
	return false;
}

