// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "HealthSystem.h"
#include "Perception/PawnSensingComponent.h"
#include "Components/CapsuleComponent.h"


AEnemy::AEnemy() {
	 HealthSystemComponent = CreateDefaultSubobject<UHealthSystem>(TEXT("Health"));
	 pawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing"));
	 GetCapsuleComponent()->SetCollisionProfileName("Enemy");

	 AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AEnemy::takeDamage_Implementation(float ammount) {
	HealthSystemComponent->takeDamage(ammount);

	if (HealthSystemComponent->isDead()) {
		die_Implementation();          
	}

}

void AEnemy::heal_Implementation(float ammount) {
	 HealthSystemComponent->heal(ammount);
}

void AEnemy::die_Implementation() {  
	GetCapsuleComponent()->SetCollisionProfileName("BlockAll");
}

void AEnemy::Tick(float DeltaSeconds) {

	Super::Tick(DeltaSeconds);


	if (GetVelocity().X < 0) {
		SetActorRotation( FRotator(0, 180, 0));
    } 
	else if (GetVelocity().X > 0){
		SetActorRotation(FRotator(0));
	}

}
