// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractItem.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AAbstractItem::AAbstractItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));

	RootComponent = collider;

    staticMesh->SetupAttachment(RootComponent);
	collider->OnComponentBeginOverlap.AddDynamic(this, &AAbstractItem::action);


}

// Called when the game starts or when spawned
void AAbstractItem::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AAbstractItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAbstractItem::action(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {}

