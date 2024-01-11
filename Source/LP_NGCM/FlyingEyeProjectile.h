// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseProjectile.h"
#include "FlyingEyeProjectile.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AFlyingEyeProjectile : public ABaseProjectile
{
	GENERATED_BODY()

public:
	AFlyingEyeProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
