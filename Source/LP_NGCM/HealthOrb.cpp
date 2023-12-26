// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthOrb.h"
#include "HealthSystemUsage.h"

AHealthOrb::AHealthOrb() : Super(){ 
}

void AHealthOrb::BeginPlay() { Super::BeginPlay(); }

void AHealthOrb::action(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

    UE_LOG(LogTemp, Display, TEXT("ORB"));
    if (IHealthSystemUsage *other = Cast<IHealthSystemUsage>(OtherActor)) {
          other->heal_Implementation(25);
	}
    Destroy();
}

void AHealthOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
