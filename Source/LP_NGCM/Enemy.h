// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HealthSystemUsage.h"
#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API AEnemy : public APaperZDCharacter,  public IHealthSystemUsage
{
	GENERATED_BODY()
public:
	AEnemy();

	/** Health System*/
	UPROPERTY(EditAnywhere, Category = "Health System")
    class UHealthSystem* HealthSystemComponent;

	UPROPERTY(EditAnywhere, Category = "AI")
    class UPawnSensingComponent* pawnSensingComponent;


	void takeDamage_Implementation(float ammount) override;
	void heal_Implementation(float ammount) override;
	void die_Implementation() override;
	UFUNCTION(BlueprintCallable)
        UHealthSystem *getHealthSystemComponent() {return HealthSystemComponent;}

	 UFUNCTION(BlueprintImplementableEvent)
 void HurtAnim();


 UFUNCTION(BlueprintImplementableEvent)
 void DieAnim();

 UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) 
	void Attack();


	virtual void Tick(float DeltaSeconds);
};
