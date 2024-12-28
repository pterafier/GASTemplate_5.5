// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/JamAssetManager.h"
#include "AbilitySystem/JamGameplayTags.h"

UJamAssetManager& UJamAssetManager::Get()
{
	check(GEngine);

	UJamAssetManager* JamAssetManager = Cast<UJamAssetManager>(GEngine->AssetManager);
	return *JamAssetManager;
}

void UJamAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FJamGameplayTags::InitializeNativeGameplayTags();
}
