#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CGamePController.generated.h"

UCLASS()
class MAZECRAWLERX_API ACGamePController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACGamePController();

	void BeginPlay() override;
};
