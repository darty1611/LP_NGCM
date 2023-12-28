// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HealthSystemUsage.h"
#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Red.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UHealthSystem;
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

	/** Health System*/
	UPROPERTY(EditAnywhere, Category = "Health System")
    class UHealthSystem* HealthSystemComponent;

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
	UFUNCTION(BlueprintCallable)
        UHealthSystem *getHealthSystemComponent() {return HealthSystemComponent;}
};
