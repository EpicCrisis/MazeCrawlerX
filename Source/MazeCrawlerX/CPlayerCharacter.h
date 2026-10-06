#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "CPlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpotLightComponent;
class UCameraComponent;
class ACFoodManager;
class UCPlayerHUD;

UCLASS()
class MAZECRAWLERX_API ACPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> m_CameraComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light")
	TObjectPtr<USpotLightComponent> m_PointLightComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* DefaultMappingContext = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Manager")
	TObjectPtr<ACFoodManager> m_FoodManager = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UCPlayerHUD> m_PlayerHUDClass = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UCPlayerHUD* m_PlayerHUD = nullptr;

	//head bob effect
	UPROPERTY(EditAnywhere, Category = "Camera Bob")
	float m_BobSpeed = 8.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Bob")
	float m_BobAmount = 3.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Bob")
	float m_BobSideAmount = 1.5f;
	UPROPERTY()
	float m_BobTime = 0.0f;
	UPROPERTY()
	FVector m_CameraBaseLocation = FVector::ZeroVector;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PawnClientRestart() override;
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
