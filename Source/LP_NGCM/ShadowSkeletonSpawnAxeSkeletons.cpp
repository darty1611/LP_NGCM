// Fill out your copyright notice in the Description page of Project Settings.


#include "ShadowSkeletonSpawnAxeSkeletons.h"
#include "ShadowSkeleton.h"

void UShadowSkeletonSpawnAxeSkeletons::OnReceiveNotify_Implementation(
    UPaperZDAnimInstance *OwningInstance) {

    if (IsValid(OwningInstance)) {

        AShadowSkeleton *owner = Cast<AShadowSkeleton>(OwningInstance->GetOwningActor());

        if (IsValid(owner)) {

            owner->spawnAxeSkeletons();
            
        }

    }
    


}
