// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "JamAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API UJamAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UJamAttributeSet();

/**
 * Vital Attributes
 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, Health);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, MaxHealth);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, Mana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, MaxMana);
	
/**
 * Primary Attributes
 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, Strength);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Primary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, Dexterity);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, Vigor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UJamAttributeSet, Intelligence);

public:

	// Used to clamp internal values of attributes
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	// Collects data from PostGameplayEffectExecute and stores it in a struct FEffectProperties. We also clamp attribute values here again
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};
