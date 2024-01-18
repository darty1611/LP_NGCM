// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeEnemy.h"
#include "Components/BoxComponent.h"

AMeleeEnemy::AMeleeEnemy() {

	attackBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Attack Box"));
	attackBox->SetCollisionProfileName("NoCollision");
	attackBox->SetupAttachment(RootComponent);
    attackBox->OnComponentBeginOverlap.AddDynamic(this, &AMeleeEnemy::AttackHit);


}



void AMeleeEnemy::AttackHit(UPrimitiveComponent *OverlappedComponent,
                            AActor *OtherActor, UPrimitiveComponent *OtherComp,
                            int32 OtherBodyIndex, bool bFromSweep,
                            const FHitResult &SweepResult) {

    UE_LOG(LogTemp, Display, TEXT("acertei"));
    if (IHealthSystemUsage* other = Cast<IHealthSystemUsage>(OtherActor) ){

        other->takeDamage_Implementation(baseDamage);
    }



    disableAttackBox();

}

void AMeleeEnemy::enableAttackBox() { 
    attackBox->SetCollisionProfileName("EnemyWeapon");
    
}

void AMeleeEnemy::disableAttackBox() {
    attackBox->SetCollisionProfileName("NoCollision");

}


