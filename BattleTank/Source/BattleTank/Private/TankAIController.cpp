// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/// Find and report the AI Tank
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Possessed Tank %s"), *(ControlledTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Failed to possess tank"));
	}

	/// Find and report the Player Tank
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Possessed Tank %s"), *(PlayerTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Failed to possess Player tank"));
	}

}

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	if (!GetControlledTank()) { return; }
	if (GetPlayerTank()) {
		// TODO Move towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); 
}


