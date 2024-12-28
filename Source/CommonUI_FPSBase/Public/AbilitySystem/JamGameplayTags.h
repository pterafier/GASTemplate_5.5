// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 * Singleton containing native Gameplay Tags
 */


struct FJamGameplayTags
{
public:
	static const FJamGameplayTags& Get() {return GameplayTags;}
	static void InitializeNativeGameplayTags();

	/** Vital Attribute Tags */
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_MaxHealth;
	FGameplayTag Attributes_Vital_Mana;
	FGameplayTag Attributes_Vital_MaxMana;

	/** Primary Attribute Tags */
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Vigor;
	FGameplayTag Attributes_Primary_Intelligence;

	/** Debuff Tags */
	FGameplayTag Effects_Debuffs_OnFire;
	FGameplayTag Effects_Debuffs_Stunned;
	
protected:
	
	/** Input Tags */
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
	FGameplayTag InputTag_Space; // Bound to jump
	FGameplayTag InputTag_Move; // Do not use
	FGameplayTag InputTag_Look; // Do not use
	FGameplayTag InputTag_E; // Bound to interact
	FGameplayTag InputTag_Tab; // Bound to pause menu, but this is only for development purposes. The pause menu will be moved to ESC
	FGameplayTag InputTag_Esc; // Bound to pause menu

private:
	static FJamGameplayTags GameplayTags;
};