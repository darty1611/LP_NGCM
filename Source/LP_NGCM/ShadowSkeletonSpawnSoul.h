// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Notifies/PaperZDAnimNotify.h"
#include "ShadowSkeletonSpawnSoul.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API UShadowSkeletonSpawnSoul : public UPaperZDAnimNotify
{
	GENERATED_BODY()
	

public:

	void OnReceiveNotify_Implementation(UPaperZDAnimInstance* OwningInstance = nullptr) override;
};
