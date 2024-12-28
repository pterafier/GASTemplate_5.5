// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "JamAssetManager.generated.h"



/**
 * Initializes gameplay tags.
 */
UCLASS()
class COMMONUI_FPSBASE_API UJamAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	static UJamAssetManager& Get();

protected: 

	virtual void StartInitialLoading();
	
};
