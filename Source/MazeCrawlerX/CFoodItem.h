#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CFoodItem.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class USphereComponent;
class ACFoodManager;

UCLASS()
class MAZECRAWLERX_API ACFoodItem : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* m_SceneComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* m_StaticMeshComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
	TArray<UStaticMesh*> m_FoodMeshes;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	USphereComponent* m_CollisionComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manager")
	ACFoodManager* m_FoodManager = nullptr;

	ACFoodItem();

	UFUNCTION(BlueprintCallable, Category = "Food")
	void SetFoodMesh(int32 Index);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
