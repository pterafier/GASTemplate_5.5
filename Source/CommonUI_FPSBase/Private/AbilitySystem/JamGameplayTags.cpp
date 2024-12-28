// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/JamGameplayTags.h"
#include "GameplayTagsManager.h"

FJamGameplayTags FJamGameplayTags::GameplayTags;

void FJamGameplayTags::InitializeNativeGameplayTags()
{
	/** Vital Attribute Tags */
	GameplayTags.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Health"), FString("Object health"));
	GameplayTags.Attributes_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.MaxHealth"), FString("Object's maximum health"));
	GameplayTags.Attributes_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Mana"), FString("Object Mana"));
	GameplayTags.Attributes_Vital_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.MaxMana"), FString("Object's Maximum Mana"));

	/** Primary Attribute Tags */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Object's Strength"));
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Dexterity"), FString("Object's Dexterity"));
	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"), FString("Object's Vigor"));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Object's Intelligence"));

	/** Debuff Tags */
	GameplayTags.Effects_Debuffs_OnFire = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Debuffs.OnFire"), FString("Applied when the object is on fire"));
	GameplayTags.Effects_Debuffs_Stunned = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Debuffs.Stunned"), FString("Applied when the object is stunned"));

	/** Input Tags */
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.LMB"), FString("Triggered on left mouse button input"));
	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.RMB"), FString("Triggered on Right mouse button input"));
	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.1"), FString("Triggered on 1 input"));
	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.2"), FString("Triggered on 2 input"));
	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.3"), FString("Triggered on 3 input"));
	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.4"), FString("Triggered on 4 input"));
	GameplayTags.InputTag_Space = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.Space"), FString("Triggered on Spacebar input"));
	GameplayTags.InputTag_Move = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.Move"), FString("Triggered on WASD input"));
	GameplayTags.InputTag_Look = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.Look"), FString("Triggered on mouse movement"));
	GameplayTags.InputTag_E = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.E"), FString("Triggered on E input"));
	GameplayTags.InputTag_Tab = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.Tab"), FString("Triggered on Tab input"));
	GameplayTags.InputTag_Esc = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.Esc"), FString("Triggered on Escape input"));


}
