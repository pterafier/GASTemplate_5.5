// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/JamAbilitySystemComponent.h"
#include "AbilitySystem/JamGameplayTags.h"
#include "AbilitySystem/Abilities/JamGameplayAbilityBase.h"

void UJamAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UJamAbilitySystemComponent::EffectApplied); // bind callback function for responding to effects when they're applied
}

void UJamAbilitySystemComponent::AddStartupAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const UJamGameplayAbilityBase* Ability = Cast<UJamGameplayAbilityBase>(AbilitySpec.Ability))
		{
			AbilitySpec.GetDynamicSpecSourceTags().AddTag(Ability->StartupInputTag); // Lecture 103 uses AbilitySpec.DynamicAbilityTags.AddTag - changed because of deprication
			GiveAbility(AbilitySpec);
		}
	}
}

void UJamAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;
	
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UJamAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;
	
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UJamAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;
	
	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
		}
	}
}

void UJamAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer; // Create a tag container
	EffectSpec.GetAllAssetTags(TagContainer); // Get all tags. Can use asset tags, granted tags, etc. Many container types to choose from but this is all tags that are applied to the effect
	
	EffectAssetTags.Broadcast(TagContainer);
	OnEffectAssetTagsChanged.Broadcast(TagContainer); // can bind to this in Blueprint to display UI elements based on a gameplay tag when an effect is applied
	
	for (FGameplayTag Tag : TagContainer)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, FString::Printf(TEXT("%s effect applied!"), *Tag.ToString()));
	}
}
