// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeEnemy.h"
#include "AxeSkeleton.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AAxeSkeleton : public AMeleeEnemy
{
	GENERATED_BODY()
public:
  AAxeSkeleton();

 void takeDamage_Implementation(float ammount) override;
 void die_Implementation() override;
 //virtual void AttackHit( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) override;
};
