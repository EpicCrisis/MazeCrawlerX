#include "CFoodSpawner.h"
#include "CFoodItem.h"
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"
#include "CFoodManager.h"

ACFoodSpawner::ACFoodSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	m_SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = m_SceneComponent;
	m_Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	m_Billboard->SetupAttachment(m_SceneComponent);
}

void ACFoodSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACFoodSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACFoodSpawner::SpawnFood()
{
	m_SpawnedFoodItem = GetWorld()->SpawnActor<ACFoodItem>(m_FoodItemClass, GetActorLocation(), GetActorRotation());
	m_SpawnedFoodItem->m_FoodManager = m_FoodManager;
}

