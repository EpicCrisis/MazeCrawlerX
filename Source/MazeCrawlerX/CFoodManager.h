#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CFoodManager.generated.h"

class ACFoodSpawner;
class ACFoodItem;
class ACPlayerCharacter;
class UCPlayerHUD;
class UBillboardComponent;

UCLASS()
class MAZECRAWLERX_API ACFoodManager : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere)
	int32 m_MaxFoodCount = 0;
	UPROPERTY(VisibleAnywhere)
	int32 m_CollectedFoodCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool m_AlwaysSpawn = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
	TArray<ACFoodSpawner*> m_FoodSpawners;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* m_SceneComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBillboardComponent* m_Billboard = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	TObjectPtr<ACPlayerCharacter> m_PlayerCharacter = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "UI")
	TObjectPtr<UCPlayerHUD> m_PlayerHUD = nullptr;

	ACFoodManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnFoodCollected(ACFoodItem* CollectedFoodItem);
	UFUNCTION()
	void SetupMaxFood();
};
