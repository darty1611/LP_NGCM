// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LP_NGCM_API UHealthSystem : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Health)
        float health;

	UPROPERTY(EditAnywhere, Category = Health)
        float maxHealth;


public:	
	// Sets default values for this component's properties
	UHealthSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
        void heal(float ammount);

	UFUNCTION(BlueprintCallable)
        void takeDamage(float ammount);
	
	UFUNCTION(BlueprintCallable)
        float getHealth();

	UFUNCTION(BlueprintCallable)
        float getMaxHealth() {return maxHealth;}

	UFUNCTION(BlueprintCallable)
        bool isFullHealth(float ammount);

	UFUNCTION(BlueprintCallable)
        bool isDead();
};
