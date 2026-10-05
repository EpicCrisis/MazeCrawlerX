#include "CMainMenuUI.h"
#include "CMainMenuPController.h"
#include "CLevelSelect.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"

void UCMainMenuUI::OnStartGameClicked()
{
	MainMenuPanel->SetVisibility(ESlateVisibility::Collapsed);
	LevelSelectMenu->SetVisibility(ESlateVisibility::Visible);
	BackButton->SetVisibility(ESlateVisibility::Visible);
}

void UCMainMenuUI::OnQuitGameClicked()
{
	//get player controller
	ACMainMenuPController* PC = Cast<ACMainMenuPController>(GetWorld()->GetFirstPlayerController());
	if (PC)
	{
		PC->QuitGame();
	}
}

void UCMainMenuUI::OnBackButtonClicked()
{
	MainMenuPanel->SetVisibility(ESlateVisibility::Visible);
	LevelSelectMenu->SetVisibility(ESlateVisibility::Collapsed);
	BackButton->SetVisibility(ESlateVisibility::Collapsed);
}
