// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Notifies/PaperZDAnimNotifyState.h"
#include "MeleeEnemyAttackNotifyState.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API UMeleeEnemyAttackNotifyState : public UPaperZDAnimNotifyState
{
	GENERATED_BODY()

	void OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) override;


	void OnNotifyEnd_Implementation(UPaperZDAnimInstance* OwningInstance) override;

	
};
