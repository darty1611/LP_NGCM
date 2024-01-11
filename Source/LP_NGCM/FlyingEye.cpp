// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingEye.h"

void AFlyingEye::takeDamage_Implementation(float ammount) {
	Super::takeDamage_Implementation(ammount);
	HurtAnim(); }

void AFlyingEye::die_Implementation() { 
	DieAnim(); 
}

