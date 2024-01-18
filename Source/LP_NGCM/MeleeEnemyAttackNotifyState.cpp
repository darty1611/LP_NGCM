// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeEnemyAttackNotifyState.h"

#include "MeleeEnemy.h"


void UMeleeEnemyAttackNotifyState::OnNotifyBegin_Implementation(
    UPaperZDAnimInstance *OwningInstance) {


        if (IsValid(OwningInstance)) {
        AMeleeEnemy* p = Cast<AMeleeEnemy>(OwningInstance->GetOwningActor());
      if (IsValid(p)) {
      
          p->enableAttackBox();
       
      }

    }


}

void UMeleeEnemyAttackNotifyState::OnNotifyEnd_Implementation(
    UPaperZDAnimInstance *OwningInstance) {

        if (IsValid(OwningInstance)) {
        AMeleeEnemy* p = Cast<AMeleeEnemy>(OwningInstance->GetOwningActor());
      if (IsValid(p)) {
      
          p->disableAttackBox();

      }

    }}
