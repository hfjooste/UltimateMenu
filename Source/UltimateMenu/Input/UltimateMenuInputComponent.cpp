#include "UltimateMenuInputComponent.h"

#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "UltimateMenu/Settings/UltimateMenuSettings.h"

void UUltimateMenuInputComponent::BeginDestroy()
{
	Super::BeginDestroy();
	if (IsValid(PlayerController))
	{
		ClearActionBindings();
		DisableInput();
	}
}

void UUltimateMenuInputComponent::Initialize(const UObject* WorldContextObject)
{
	PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (!IsValid(PlayerController))
	{
		return;
	}

	InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	if (!IsValid(InputSubsystem))
	{
		return;
	}

	const UUltimateMenuSettings* Settings = GetDefault<UUltimateMenuSettings>();
	if (!IsValid(Settings))
	{
		return;
	}

	InputMappingContext = Settings->InputMappingContext.LoadSynchronous();
	if (!IsValid(InputMappingContext))
	{
		return;
	}

	BindAction(Settings->NavigateUpInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::NavigateUp);
	BindAction(Settings->NavigateDownInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::NavigateDown);
	BindAction(Settings->NavigateLeftInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::NavigateLeft);
	BindAction(Settings->NavigateRightInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::NavigateRight);
	BindAction(Settings->TabLeftInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::TabLeft);
	BindAction(Settings->TabRightInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::TabRight);
	BindAction(Settings->SelectInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::Select);
	BindAction(Settings->BackInputAction.LoadSynchronous(),
		ETriggerEvent::Started, this, &UUltimateMenuInputComponent::Back);
	InputSubsystem->AddMappingContext(InputMappingContext, 0);
}

void UUltimateMenuInputComponent::EnableInput()
{
	if (!IsValid(PlayerController))
	{
		return;
	}

	PlayerController->PushInputComponent(this);
}

void UUltimateMenuInputComponent::DisableInput()
{
	if (!IsValid(PlayerController))
	{
		return;
	}

	PlayerController->PopInputComponent(this);
}

void UUltimateMenuInputComponent::NavigateUp()
{
	OnNavigateUp.Broadcast();
}

void UUltimateMenuInputComponent::NavigateDown()
{
	OnNavigateDown.Broadcast();
}

void UUltimateMenuInputComponent::NavigateLeft()
{
	OnNavigateLeft.Broadcast();
}

void UUltimateMenuInputComponent::NavigateRight()
{
	OnNavigateRight.Broadcast();
}

void UUltimateMenuInputComponent::TabLeft()
{
	OnTabLeft.Broadcast();
}

void UUltimateMenuInputComponent::TabRight()
{
	OnTabRight.Broadcast();
}

void UUltimateMenuInputComponent::Select()
{
	OnSelect.Broadcast();
}

void UUltimateMenuInputComponent::Back()
{
	OnBack.Broadcast();
}
