// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * BlueprintSpawnableComponent is what makes the Class available in the editor
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	// -1 is max downward speed, 1 is max upward speed
	void Elevate(float RelativeSpeed);

	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10.f; // Sensible Default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40.f; // Sensible Default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0.f; // Sensible Default
	
};
