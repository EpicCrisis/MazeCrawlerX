#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CFoodSpawner.generated.h"

class ACFoodItem;
class USceneComponent;
class UBillboardComponent;
class ACFoodManager;

UCLASS()
class MAZECRAWLERX_API ACFoodSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
	TSubclassOf<ACFoodItem> m_FoodItemClass = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* m_SceneComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBillboardComponent* m_Billboard = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Food")
	ACFoodItem* m_SpawnedFoodItem = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manager")
	ACFoodManager* m_FoodManager = nullptr;

	ACFoodSpawner();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnFood();
};
