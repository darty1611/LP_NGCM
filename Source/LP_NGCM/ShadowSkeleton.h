// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeEnemy.h"
#include "ShadowSkeleton.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AShadowSkeleton : public AMeleeEnemy
{
	GENERATED_BODY()



private:

	UPROPERTY(EditAnywhere)
	class USceneComponent* SpawnPoint1;

	UPROPERTY(EditAnywhere)
	class USceneComponent* SpawnPoint2;

	UPROPERTY(EditAnywhere)
	class USceneComponent* SpawnPoint3;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AAxeSkeleton> axeSkeletonClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AFlyingEyeProjectile> projectile;

	


public:

	AShadowSkeleton();


	void takeDamage_Implementation(float ammount) override;
	void die_Implementation() override;


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void spawnAxeSkeletonsAnim();

	void spawnAxeSkeletons();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
    void shootSoulAnim();

	void spawnSoul();

	
private:
    void spawnAxeSkeleton(FVector p);

	
};
