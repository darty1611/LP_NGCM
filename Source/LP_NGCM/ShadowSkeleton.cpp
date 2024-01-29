// Fill out your copyright notice in the Description page of Project Settings.


#include "ShadowSkeleton.h"
#include "Components/SceneComponent.h"
#include "AxeSkeleton.h"


AShadowSkeleton::AShadowSkeleton() {

	SpawnPoint1 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point 1"));
	SpawnPoint2 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point 2"));
	SpawnPoint3 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point 3"));

	SpawnPoint1->SetupAttachment(RootComponent);
	SpawnPoint2->SetupAttachment(RootComponent);
	SpawnPoint3->SetupAttachment(RootComponent);

	
}

void AShadowSkeleton::takeDamage_Implementation(float ammount) {

	Super::takeDamage_Implementation(ammount);


}

void AShadowSkeleton::die_Implementation() {

	Super::die_Implementation();

}

void AShadowSkeleton::spawnAxeSkeletons() {

	FVector sp1 = SpawnPoint1->GetComponentLocation();
	FVector sp2 = SpawnPoint2->GetComponentLocation();
	FVector sp3 = SpawnPoint3->GetComponentLocation();
	
	spawnAxeSkeleton(sp1);
	spawnAxeSkeleton(sp2);
	spawnAxeSkeleton(sp3);

	//GetWorld()->SpawnActor<AAxeSkeleton>(axeSkeletonClass, GetActorLocation() + 100, GetActorRotation(), FActorSpawnParameters());
}

void AShadowSkeleton::spawnAxeSkeleton(FVector location) {

	FActorSpawnParameters p;
	p.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	p.Owner = nullptr;
		
	GetWorld()->SpawnActor<AAxeSkeleton>(axeSkeletonClass, location, GetActorRotation(), p);

}


