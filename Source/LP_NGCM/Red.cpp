// Fill out your copyright notice in the Description page of Project Settings.


#include "Red.h"

#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Components/BoxComponent.h"
#include "BaseProjectile.h"
#include "Enemy.h"


ARed::ARed() {
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	cameraBoom->TargetArmLength = 600;

	cameraBoom->SetupAttachment(RootComponent);
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName); 
	followCamera->bUsePawnControlRotation = false;
	cameraBoom->bUsePawnControlRotation = false;
	
	cameraBoom->SetWorldRotation(FRotator(-20, -90, 0));
	
	attackBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Attack Box"));
	attackBox->SetupAttachment(RootComponent);
	disableAttackBox();
	//attackBox->OnComponentBeginOverlap.AddDynamic(this, &ARed::attackHit); //Maybe not needed anymore

 
	HealthComponent = CreateDefaultSubobject<UHealthSystem>(TEXT("HELTh"));
}

void ARed::Move(const FInputActionValue &Value) {

	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
          if (!lockRotation) {
          
			  if (MovementVector.X < 0) {
				GetCapsuleComponent()->SetWorldRotation(FRotator(0, 180, 0));
			  } else if (MovementVector.X > 0) {
				GetCapsuleComponent()->SetWorldRotation(FRotator(0,0,0));
			  }
		  }
		// add movement 
		AddMovementInput(FVector(1,0,0), MovementVector.X);
		AddMovementInput(FVector(0,-1,0), MovementVector.Y);


	}
}


void ARed::BeginPlay() {
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ARed::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARed::Move);

		// Attacking
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &ARed::Attack);

		// Shooting
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &ARed::Shoot);


	
	}
	else
	{
       
	}
}



void ARed::takeDamage_Implementation(float ammount) {
	HealthComponent->takeDamage(ammount);

	if (HealthComponent->isDead()) {
		die_Implementation();          
	}

}

void ARed::heal_Implementation(float ammount) {
	 HealthComponent->heal(ammount);
}

void ARed::die_Implementation() { 
	
}

void ARed::enableAttackBox() {
       
	attackBox->SetCollisionProfileName("Weapon");	

}

void ARed::disableAttackBox() { 
	
	attackBox->SetCollisionProfileName("NoCollision"); 

}

void ARed::attackHit(UPrimitiveComponent *OverlappedComponent,
                     AActor *OtherActor, UPrimitiveComponent *OtherComp,
                     int32 OtherBodyIndex, bool bFromSweep,
                     const FHitResult &SweepResult) {

	 //if (AEnemy* Enemy = Cast<AEnemy>(OtherActor))
  //      {
  //          // Apply damage to the enemy
  //          Enemy->takeDamage_Implementation(35);
  //          
	
	 //}

	ApplyDamageToOverlappingEnemies();

	disableAttackBox();
	

}


//try to achieve damage in area
void ARed::ApplyDamageToOverlappingEnemies()
{
    TArray<AActor*> OverlappingActors;
    attackBox->GetOverlappingActors(OverlappingActors);

    for (AActor* OverlappingActor : OverlappingActors)
    {
        if (AEnemy* Enemy = Cast<AEnemy>(OverlappingActor))
        {
            // Apply damage to the enemy
            Enemy->takeDamage_Implementation(35);
            
        }
    }
	
}

void ARed::spawnArrow() {

		FActorSpawnParameters spawnParams;
        spawnParams.Owner = this;
        spawnParams.SpawnCollisionHandlingOverride =
            ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


		FVector projectilePosition = GetActorLocation() + GetActorForwardVector() * 200;

		GetWorld()->SpawnActor<ABaseProjectile>(projectile, projectilePosition, FRotator(), spawnParams);

}

