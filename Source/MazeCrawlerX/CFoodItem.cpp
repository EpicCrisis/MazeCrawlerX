#include "CFoodItem.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "CFoodManager.h"

ACFoodItem::ACFoodItem()
{
	PrimaryActorTick.bCanEverTick = true;

	m_SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = m_SceneComponent;
	m_StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	m_StaticMeshComponent->SetupAttachment(m_SceneComponent);
	m_StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	m_StaticMeshComponent->SetCollisionProfileName("NoCollision");

	m_CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	m_CollisionComponent->SetupAttachment(m_SceneComponent);
	m_CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);   
	m_CollisionComponent->SetCollisionProfileName("OverlapAll");
}

void ACFoodItem::SetFoodMesh(int32 Index)
{
	if (m_FoodMeshes.IsValidIndex(Index))
	{
		m_StaticMeshComponent->SetStaticMesh(m_FoodMeshes[Index]);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid index for food mesh: %d"), Index);
	}
}

void ACFoodItem::BeginPlay()
{
	Super::BeginPlay();

	m_CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACFoodItem::OnOverlapBegin);
	m_CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ACFoodItem::OnOverlapEnd);

	int32 randomFood = 0;
	randomFood = FMath::RandRange(0, m_FoodMeshes.Num() - 1);
	SetFoodMesh(randomFood);
}

void ACFoodItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACFoodItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//check if the other actor is the player character
	if(OtherActor && OtherActor != this)
	{
		if(OtherActor->ActorHasTag(FName("Player")))
		{
			//play sound
			UGameplayStatics::PlaySoundAtLocation(this, Cast<USoundBase>(StaticLoadObject(USoundBase::StaticClass(), nullptr, TEXT("/Game/Sounds/CollectSound.CollectSound"))), GetActorLocation());
			//disable this actor
			SetActorEnableCollision(false);
			SetActorHiddenInGame(true);

			if (m_FoodManager)
			{
				m_FoodManager->OnFoodCollected(this);
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s"), *OtherActor->GetName());
}

void ACFoodItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

