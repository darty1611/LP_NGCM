// Fill out your copyright notice in the Description page of Project Settings.


#include "RedAttackNotifyState.h"
#include "Red.h"

void URedAttackNotifyState::OnNotifyBegin_Implementation(
    UPaperZDAnimInstance *OwningInstance) {

    if (IsValid(OwningInstance)) {
        ARed* p = Cast<ARed>(OwningInstance->GetOwningActor());
      if (IsValid(p)) {
      
          p->enableAttackBox();
          p->ApplyDamageToOverlappingEnemies();

      }

    }
   
 

}

void URedAttackNotifyState::OnNotifyEnd_Implementation(
    UPaperZDAnimInstance *OwningInstance) {

      if (IsValid(OwningInstance)) {
        ARed* p = Cast<ARed>(OwningInstance->GetOwningActor());
      if (IsValid(p)) {
      
            p->disableAttackBox();


      }

      }
    
}
