// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class LP_NGCM_API ABaseProjectile : public AActor
{
GENERATED_BODY()


	UPROPERTY(EditAnywhere, Category = StaticMesh)
        class UStaticMeshComponent *staticMesh;

	UPROPERTY(EditAnywhere, Category = StaticMesh)
        class USphereComponent* sphereCollider;

	UPROPERTY(EditAnywhere, Category = StaticMesh)
        class UProjectileMovementComponent *projectileMovement;

	UPROPERTY(EditAnywhere, Category = Damage)
		float damage;
		


	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
      virtual void OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
