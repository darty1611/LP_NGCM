// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingEye.h"

#include "FlyingEyeProjectile.h"
#include "Kismet/GameplayStatics.h"

AFlyingEye::AFlyingEye() {


}

void AFlyingEye::takeDamage_Implementation(float ammount) {
	Super::takeDamage_Implementation(ammount);
	HurtAnim(); }

void AFlyingEye::die_Implementation() { 
	DieAnim(); 
}

void AFlyingEye::spawnProjectile() {
FActorSpawnParameters spawnParams;
        spawnParams.Owner = this;
        spawnParams.SpawnCollisionHandlingOverride =
            ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


		FVector projectilePosition = GetActorTransform().GetLocation() + (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()).Normalize();
		


		GetWorld()->SpawnActor<ABaseProjectile>(projectile, projectilePosition, FRotator(), spawnParams);
}

