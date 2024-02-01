// Fill out your copyright notice in the Description page of Project Settings.


#include "ShadowSkeletonSpawnSoul.h"
#include "ShadowSkeleton.h"


void UShadowSkeletonSpawnSoul::OnReceiveNotify_Implementation(
    UPaperZDAnimInstance *OwningInstance) {

    
    if (IsValid(OwningInstance)) {

        AShadowSkeleton *owner = Cast<AShadowSkeleton>(OwningInstance->GetOwningActor());

        if (IsValid(owner)) {

            owner->spawnSoul();
            
        }

    }


}
