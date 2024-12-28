// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HUDController.generated.h"

class AJamPlayerState;
class UAbilitySystemComponent;
class UJamAttributeSet;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChanged, float, NewValue);

UCLASS()
class COMMONUI_FPSBASE_API AHUDController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHUDController();

public:

	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitialValues();

	UFUNCTION(BlueprintCallable)
	virtual void BindCallbacksToDependencies();

	UPROPERTY(BlueprintReadOnly, Category = "GAS")
	AJamPlayerState* PlayerState;
	
	UPROPERTY(BlueprintReadOnly, Category = "GAS")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "GAS")
	const UJamAttributeSet* AttributeSet; 

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChanged OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChanged OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChanged OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChanged OnMaxManaChanged;
	
};
