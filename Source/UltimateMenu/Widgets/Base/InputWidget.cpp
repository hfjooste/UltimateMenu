#include "InputWidget.h"

#include "UltimateMenu/Input/UltimateMenuInputComponent.h"

void UInputWidget::NativeConstruct()
{
	Super::NativeConstruct();

	WidgetInputComponent = NewObject<UUltimateMenuInputComponent>(this);
	WidgetInputComponent->Initialize(GetWorld());
	
	WidgetInputComponent->OnNavigateUp.AddDynamic(this, &UInputWidget::NavigateUp);
	WidgetInputComponent->OnNavigateDown.AddDynamic(this, &UInputWidget::NavigateDown);
	WidgetInputComponent->OnNavigateLeft.AddDynamic(this, &UInputWidget::NavigateLeft);
	WidgetInputComponent->OnNavigateRight.AddDynamic(this, &UInputWidget::NavigateRight);
	WidgetInputComponent->OnTabLeft.AddDynamic(this, &UInputWidget::TabLeft);
	WidgetInputComponent->OnTabRight.AddDynamic(this, &UInputWidget::TabRight);
	WidgetInputComponent->OnSelect.AddDynamic(this, &UInputWidget::Select);
	WidgetInputComponent->OnBack.AddDynamic(this, &UInputWidget::Back);
}

void UInputWidget::EnableInput() const
{
	if (IsValid(WidgetInputComponent))
	{
		WidgetInputComponent->EnableInput();
	}
}

void UInputWidget::DisableInput() const
{
	if (IsValid(WidgetInputComponent))
	{
		WidgetInputComponent->DisableInput();
	}
}

void UInputWidget::NavigateUp()
{
}

void UInputWidget::NavigateDown()
{
}

void UInputWidget::NavigateLeft()
{
}

void UInputWidget::NavigateRight()
{
}

void UInputWidget::TabLeft()
{
}

void UInputWidget::TabRight()
{
}

void UInputWidget::Select()
{
}

void UInputWidget::Back()
{
}
