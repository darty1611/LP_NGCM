// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingEyeProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"

AFlyingEyeProjectile::AFlyingEyeProjectile() {

    projectileMovement->InitialSpeed = 1000;

}

void AFlyingEyeProjectile::BeginPlay() {
    
  Super::BeginPlay();
   UE_LOG(LogTemp, Warning, TEXT("Initial"));
    

    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

    if (PlayerController)
    {
        // Get the pawn controlled by the player controller
        APawn* PlayerPawn = PlayerController->GetPawn();
      
        if (PlayerPawn)
        {
            // Get the location of the player pawn
            FVector PlayerLocation = PlayerPawn->GetActorLocation();

            // Now you have the player location in the variable 'PlayerLocation'
            // You can use it as needed
            projectileMovement->SetVelocityInLocalSpace((PlayerLocation - GetActorLocation()).GetSafeNormal() * projectileMovement->InitialSpeed);
            // projectileMovement->SetVelocityInLocalSpace( FVector(0,1,0) * 2000);

             UE_LOG(LogTemp, Warning, TEXT("Initial speed: %d"), projectileMovement->InitialSpeed);
            UE_LOG(LogTemp, Warning, TEXT("Player Location: %s"), *PlayerLocation.ToString());
        }
    }
}
