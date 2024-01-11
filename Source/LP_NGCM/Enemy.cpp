// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "HealthSystem.h"
#include "Perception/PawnSensingComponent.h"


AEnemy::AEnemy() {
	 HealthSystemComponent = CreateDefaultSubobject<UHealthSystem>(TEXT("Health"));
	 pawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing"));
	//GetCapsuleComponent()->SetCollisionProfileName("NoCollision");
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
	Destroy(); 
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
