// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	void AimAt(FVector);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelTurretReferences(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


protected:
	UTankAimingComponent * TankAimingComponent = nullptr;

private:
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	 
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000; // TODO find sesible default
};
