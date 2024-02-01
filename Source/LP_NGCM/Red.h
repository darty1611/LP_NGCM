// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HealthSystemUsage.h"
#include "HealthSystem.h"
#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Red.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


/**
 * 
 */
UCLASS()
class LP_NGCM_API ARed : public APaperZDCharacter, public IHealthSystemUsage
{
	GENERATED_BODY()

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* cameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* followCamera;


	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	/** Attack Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AttackAction;
	
	/** Shoot Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ShootAction;

	/**Combat*/
	UPROPERTY(EditAnywhere, Category = "Combat")
	class UBoxComponent* attackBox;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float baseDamage = 20;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class ABaseProjectile> projectile;

	/** Health System*/
	UPROPERTY(EditAnywhere, Category = "Health System")
    UHealthSystem* Health;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool lockRotation = false;


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	ARed();

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

public:
	void takeDamage_Implementation(float ammount) override;
	void heal_Implementation(float ammount) override;
	void die_Implementation() override;
	UFUNCTION(BlueprintImplementableEvent) 
	void DieAnim();
	UFUNCTION(BlueprintCallable)
       UHealthSystem *getHealthSystemComponent() {return Health;}

	UFUNCTION(BlueprintImplementableEvent) 
	void Attack();
	void enableAttackBox();
	void disableAttackBox();
	UFUNCTION()
	void attackHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void ApplyDamageToOverlappingEnemies();


	UFUNCTION(BlueprintImplementableEvent) 
	void Shoot();
	UFUNCTION(BlueprintCallable)
	void spawnArrow();

};
