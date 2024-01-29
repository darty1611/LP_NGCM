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
	TSubclassOf<AController> axeSkeletonController;

public:

	AShadowSkeleton();


	void takeDamage_Implementation(float ammount) override;
	void die_Implementation() override;



	void spawnAxeSkeletons();
    void shootSoul();

	
private:
    void spawnAxeSkeleton(FVector p);

	
};
