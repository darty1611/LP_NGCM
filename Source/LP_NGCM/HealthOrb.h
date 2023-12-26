// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractItem.h"
#include "HealthOrb.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AHealthOrb : public AAbstractItem
{
	GENERATED_BODY()
	

public:

	AHealthOrb();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void action(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
