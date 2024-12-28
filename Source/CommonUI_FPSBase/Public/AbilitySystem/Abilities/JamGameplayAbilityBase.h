// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "JamGameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API UJamGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;
	
};
