// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeEnemy.h"
#include "Mushroom.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AMushroom : public AMeleeEnemy
{
	GENERATED_BODY()

public:

AMushroom();

void takeDamage_Implementation(float ammount) override;
void die_Implementation() override;

	
};
