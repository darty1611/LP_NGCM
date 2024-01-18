// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "MeleeEnemy.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AMeleeEnemy : public AEnemy
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* attackBox;

	UPROPERTY(EditAnywhere)
	float baseDamage = 0;

public:
	AMeleeEnemy();

private:
	UFUNCTION()
	virtual void AttackHit( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

public:
	void enableAttackBox();
	void disableAttackBox();
};
