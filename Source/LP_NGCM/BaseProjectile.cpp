// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"

#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "HealthSystemUsage.h"

// Sets default values
ABaseProjectile::ABaseProjectile() 
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));

	RootComponent = sphereCollider;

	staticMesh =
            CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Stattic Mesh"));
	
	staticMesh->SetupAttachment(sphereCollider);

	projectileMovement =
            CreateDefaultSubobject<UProjectileMovementComponent>(
                TEXT("Projectile Movement"));
	sphereCollider->SetGenerateOverlapEvents(true);

	sphereCollider->SetCollisionProfileName("Weapon");
	sphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ABaseProjectile::OnHit);

	damage = 35;

}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();

	int xvel = GetOwner()->GetActorRotation().Yaw == 0 ? 1 : -1;


	projectileMovement->SetVelocityInLocalSpace(FVector(xvel, 0, 0) * projectileMovement->InitialSpeed);
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::OnHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)  {
	
	if (IHealthSystemUsage *other = Cast<IHealthSystemUsage>(OtherActor)) {
          other->takeDamage_Implementation(damage);
	}

	Destroy();

}