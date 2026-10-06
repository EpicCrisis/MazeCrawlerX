#include "CGamePController.h"
#include "EnhancedInputSubsystems.h"

ACGamePController::ACGamePController()
{
}

void ACGamePController::BeginPlay()
{
	bShowMouseCursor = false;
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
