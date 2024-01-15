// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "FlyingEye.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AFlyingEye : public AEnemy
{
	GENERATED_BODY()

public:
	AFlyingEye();

private:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class ABaseProjectile> projectile;


public:
	
	void takeDamage_Implementation(float ammount) override;
	void die_Implementation() override;

	UFUNCTION(BlueprintCallable)
	void spawnProjectile();
};
