// Fill out your copyright notice in the Description page of Project Settings.


#include "AxeSkeleton.h"
#include "PaperZDPlaySlotOverrideAction.h"

AAxeSkeleton::AAxeSkeleton() {
	baseDamage = 5;
}

void AAxeSkeleton::takeDamage_Implementation(float ammount) {
  Super::takeDamage_Implementation(ammount);

  HurtAnim();

}

void AAxeSkeleton::die_Implementation() {

	Super::die_Implementation();
	DieAnim(); 

}
