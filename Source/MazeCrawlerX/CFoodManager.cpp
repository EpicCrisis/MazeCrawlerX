#include "CFoodManager.h"
#include "CFoodSpawner.h"
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"
#include "CPlayerHUD.h"

ACFoodManager::ACFoodManager()
{
	PrimaryActorTick.bCanEverTick = true;

	m_SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = m_SceneComponent;
	m_Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	m_Billboard->SetupAttachment(m_SceneComponent);
}

void ACFoodManager::BeginPlay()
{
	Super::BeginPlay();
	for(int32 i = 0; i < m_FoodSpawners.Num(); i++)
	{
		int32 allowSpawn = FMath::RandRange(0, 1);
		if (m_AlwaysSpawn)
		{
			allowSpawn = 1;
		}
		if (allowSpawn == 1)
		{
			if (m_FoodSpawners[i])
			{
				m_FoodSpawners[i]->m_FoodManager = this;
				m_FoodSpawners[i]->SpawnFood();
				++m_MaxFoodCount;
			}
		}
	}
}

void ACFoodManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACFoodManager::OnFoodCollected(ACFoodItem* CollectedFoodItem)
{
	if (CollectedFoodItem)
	{
		++m_CollectedFoodCount;
		if (m_PlayerHUD)
		{
			m_PlayerHUD->UpdateFoodCollected(m_CollectedFoodCount);
		}
	}
}

void ACFoodManager::SetupMaxFood()
{
	m_PlayerHUD->UpdateMaxFoodCount(m_MaxFoodCount);
}



