// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Controllers/HUDController.h"
#include "AbilitySystem/AttributeSets/JamAttributeSet.h"
#include "AbilitySystem/JamAbilitySystemComponent.h"
#include "Player/JamPlayerState.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHUDController::AHUDController()
{

}

void AHUDController::BroadcastInitialValues()
{
	OnHealthChanged.Broadcast(AttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AttributeSet->GetMaxMana());
}

void AHUDController::BindCallbacksToDependencies()
{
	PlayerState = Cast<AJamPlayerState>(UGameplayStatics::GetPlayerState(this, 0));
	AbilitySystemComponent = CastChecked<UJamAbilitySystemComponent>(PlayerState->GetAbilitySystemComponent());
	AttributeSet = Cast<UJamAttributeSet>(AbilitySystemComponent->GetAttributeSet(UJamAttributeSet::StaticClass()));

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
	);
}

