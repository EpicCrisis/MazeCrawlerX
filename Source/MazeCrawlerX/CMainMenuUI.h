#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CMainMenuUI.generated.h"

class UTextBlock;
class UButton;
class UCLevelSelect;
class UCanvasPanel;

UCLASS()
class MAZECRAWLERX_API UCMainMenuUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* MainMenuPanel = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText = nullptr;
	UPROPERTY(meta = (BindWidget))
	UButton* StartGameButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	UButton* QuitGameButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	UButton* BackButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UCLevelSelect* LevelSelectMenu = nullptr;

	UFUNCTION(BlueprintCallable)
	void OnStartGameClicked();
	UFUNCTION(BlueprintCallable)
	void OnQuitGameClicked();
	UFUNCTION(BlueprintCallable)
	void OnBackButtonClicked();
};
