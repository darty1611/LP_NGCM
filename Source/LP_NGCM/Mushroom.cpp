// Fill out your copyright notice in the Description page of Project Settings.


#include "Mushroom.h"


AMushroom::AMushroom() {
	baseDamage = 10;
}

void AMushroom::takeDamage_Implementation(float ammount) { 

	Super::takeDamage_Implementation(ammount);
	HurtAnim(); 
}

void AMushroom::die_Implementation() { 
	Super::die_Implementation();
	DieAnim(); 
}
