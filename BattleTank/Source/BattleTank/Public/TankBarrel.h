// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * BlueprintSpawnableComponent is what makes the Class available in the editor
 */
UCLASS(meta = (BlueprintSpawnableComponent),hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20.f; // Sensible Default

	UPROPERTY(EditAnywhere)
	float MaxElevation = 20.f; // Sensible Default

	UPROPERTY(EditAnywhere)
	float MinElevation = 20.f; // Sensible Default
	
};
