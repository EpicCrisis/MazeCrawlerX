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

	void BeginPlay() override;

	UFUNCTION()
	void SetupMainMenu();
	UFUNCTION()
	void QuitGame();
};
