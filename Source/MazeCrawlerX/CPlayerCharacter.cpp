#include "CPlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CFoodManager.h"
#include "CPlayerHUD.h"

ACPlayerCharacter::ACPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	m_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_CameraComponent->SetupAttachment(GetCapsuleComponent());

	m_PointLightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	m_PointLightComponent->SetupAttachment(m_CameraComponent);
}

void ACPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	m_FoodManager = Cast<ACFoodManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ACFoodManager::StaticClass()));
	m_FoodManager->m_PlayerCharacter = this;

	if (m_PlayerHUDClass)
	{
		m_PlayerHUD = CreateWidget<UCPlayerHUD>(GetWorld(), m_PlayerHUDClass);
		m_PlayerHUD->AddToViewport();

		m_FoodManager->m_PlayerHUD = m_PlayerHUD;
		m_FoodManager->SetupMaxFood();
	}
}

void ACPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPlayerCharacter::Look);
	}
}

void ACPlayerCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ACPlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void ACPlayerCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

