#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPlayerHUD.generated.h"

class UTextBlock;

UCLASS()
class MAZECRAWLERX_API UCPlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* FoodCollected = nullptr;	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MaxFood = nullptr;

	UFUNCTION(BlueprintCallable)
	void UpdateMaxFoodCount(int32 NewMaxFoodCount);
	UFUNCTION(BlueprintCallable)
	void UpdateFoodCollected(int32 NewFoodCount);
};
