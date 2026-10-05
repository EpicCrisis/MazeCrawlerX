#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CLevelSelect.generated.h"

class UButton;

UCLASS()
class MAZECRAWLERX_API UCLevelSelect : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* Level1Button = nullptr;
	UPROPERTY(meta = (BindWidget))
	UButton* Level2Button = nullptr;
	UPROPERTY(meta = (BindWidget))
	UButton* Level3Button = nullptr;

	UFUNCTION(BlueprintCallable)
	void OnLevel1Clicked();
	UFUNCTION(BlueprintCallable)
	void OnLevel2Clicked();
	UFUNCTION(BlueprintCallable)
	void OnLevel3Clicked();
};
