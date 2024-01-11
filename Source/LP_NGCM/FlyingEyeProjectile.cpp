// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingEyeProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AFlyingEyeProjectile::AFlyingEyeProjectile() {}

void AFlyingEyeProjectile::BeginPlay() {

	FVector playerPos =
      GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	projectileMovement->SetVelocityInLocalSpace(
            (playerPos - GetActorLocation()) * projectileMovement->InitialSpeed);
}
