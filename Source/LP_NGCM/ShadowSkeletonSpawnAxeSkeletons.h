// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Notifies/PaperZDAnimNotify.h"
#include "ShadowSkeletonSpawnAxeSkeletons.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API UShadowSkeletonSpawnAxeSkeletons : public UPaperZDAnimNotify
{
	GENERATED_BODY()

public:

	void OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance = nullptr) override;
	
};
