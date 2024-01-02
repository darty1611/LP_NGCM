// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "AxeSkeleton.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AAxeSkeleton : public AEnemy
{
	GENERATED_BODY()
public:
  AAxeSkeleton();

 void takeDamage_Implementation(float ammount) override;
 UFUNCTION(BlueprintImplementableEvent)
 void HurtAnim();

 void die_Implementation() override;

 UFUNCTION(BlueprintImplementableEvent)
 void DieAnim();
};
