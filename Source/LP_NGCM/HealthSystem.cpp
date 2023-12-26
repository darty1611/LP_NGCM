// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthSystem.h"

// Sets default values for this component's properties
UHealthSystem::UHealthSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	maxHealth = 100;
	health = 75;
	// ...
}


// Called when the game starts
void UHealthSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthSystem::heal(float ammount) {
        health = FMath::Min(health + ammount, maxHealth);
}
void UHealthSystem::takeDamage(float ammount) { 
	health -= ammount; }

float UHealthSystem::getHealth() { return health; }

bool UHealthSystem::isFullHealth(float ammount) {
        return health == maxHealth;
}

bool UHealthSystem::isDead() { return health <= 0; }

