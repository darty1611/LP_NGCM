// Fill out your copyright notice in the Description page of Project Settings.


#include "AxeSkeleton.h"
#include "PaperZDPlaySlotOverrideAction.h"

AAxeSkeleton::AAxeSkeleton() {

}

void AAxeSkeleton::takeDamage_Implementation(float ammount) {
  Super::takeDamage_Implementation(ammount);

  HurtAnim();

}

void AAxeSkeleton::die_Implementation() {
	DieAnim();
}
