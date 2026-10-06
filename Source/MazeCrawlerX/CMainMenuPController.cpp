#include "CMainMenuPController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACMainMenuPController::ACMainMenuPController()
{
}

void ACMainMenuPController::BeginPlay()
{
	Super::BeginPlay();
	SetupMainMenu();
}

void ACMainMenuPController::SetupMainMenu()
{
	if (MainMenuWidgetClass)
	{
		MainMenuWidget = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
	}
	if (MainMenuWidget)
	{
		MainMenuWidget->AddToViewport();

		bShowMouseCursor = true;
		FInputModeUIOnly InputMode;
		InputMode.SetWidgetToFocus(MainMenuWidget->TakeWidget());
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		SetInputMode(InputMode);
	}
}

void ACMainMenuPController::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, this, EQuitPreference::Quit, true);
}

void ACMainMenuPController::LoadLevel(FName LevelName)
{
	UGameplayStatics::OpenLevel(this, LevelName);
}
