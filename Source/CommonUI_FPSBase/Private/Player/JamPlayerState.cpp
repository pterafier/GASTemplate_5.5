// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/JamPlayerState.h"
#include "AbilitySystem/JamAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/JamAttributeSet.h"

AJamPlayerState::AJamPlayerState()
{
	// When initializing these pointers, make sure the ability system component type is the custom class. For dungeonbound, it would be <UDungeonboundAbilitySystemComponent>. The pointer
	// itself is of type UAbilitySystemComponent.
	AbilitySystemComponent = CreateDefaultSubobject<UJamAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<UJamAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AJamPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
