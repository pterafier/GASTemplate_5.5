// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "JamAbilitySystemComponent.generated.h"

/* Dynamic and native versions of the same delegates so we can use Lambda convenience but allow a blueprint callable delegate */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicEffectAssetTags, const FGameplayTagContainer&, AssetTags);
DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /*AssetTags*/);

/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API UJamAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();

	void AddStartupAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);

	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);
	void AbilityInputTagPressed(const FGameplayTag& InputTag);

public:
/**
 * Delegates
 */
	UPROPERTY(BlueprintAssignable, Category = "Effects")
	FDynamicEffectAssetTags OnEffectAssetTagsChanged;

	FEffectAssetTags EffectAssetTags;
/**
 * End Delegates
 */

protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
