#include "CLevelSelect.h"
#include "CMainMenuPController.h"

void UCLevelSelect::OnLevel1Clicked()
{
	ACMainMenuPController* PC = Cast<ACMainMenuPController>(GetWorld()->GetFirstPlayerController());
	if (PC)
	{
		PC->LoadLevel(PC->Level1Name);
	}
}

void UCLevelSelect::OnLevel2Clicked()
{
	ACMainMenuPController* PC = Cast<ACMainMenuPController>(GetWorld()->GetFirstPlayerController());
	if (PC)
	{
		PC->LoadLevel(PC->Level2Name);
	}
}

void UCLevelSelect::OnLevel3Clicked()
{
	ACMainMenuPController* PC = Cast<ACMainMenuPController>(GetWorld()->GetFirstPlayerController());
	if (PC)
	{
		PC->LoadLevel(PC->Level3Name);
	}
}
