// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Notifies/PaperZDAnimNotifyState.h"
#include "RedAttackNotifyState.generated.h"

/**
 * 
 */
UCLASS()
class LP_NGCM_API URedAttackNotifyState : public UPaperZDAnimNotifyState
{
	GENERATED_BODY()

public:
	
	void OnNotifyBegin_Implementation(UPaperZDAnimInstance* OwningInstance) override;


	void OnNotifyEnd_Implementation(UPaperZDAnimInstance* OwningInstance) override;
	
	
};
