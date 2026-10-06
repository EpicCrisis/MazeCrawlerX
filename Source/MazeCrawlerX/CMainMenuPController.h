#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CMainMenuPController.generated.h"

class UUserWidget;

UCLASS()
class MAZECRAWLERX_API ACMainMenuPController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACMainMenuPController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainMenu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass = nullptr;
	UPROPERTY()
	UUserWidget* MainMenuWidget = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSelect")
	FName Level1Name = "Level1Map";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSelect")
	FName Level2Name = "Level2Map";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSelect")
	FName Level3Name = "Level3Map";

	void BeginPlay() override;

	UFUNCTION()
	void SetupMainMenu();
	UFUNCTION()
	void QuitGame();
	UFUNCTION()
	void LoadLevel(FName LevelName);
};
