// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/JamCharacterBase.h"
#include "Data/SaveGameStructs.h"
#include "JamPlayerCharacter.generated.h"

class UJamAbilitySystemComponent;
class UGameplayAbility;
class UCameraComponent;
class AJamPlayerController;
class AJamPlayerState;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API AJamPlayerCharacter : public AJamCharacterBase
{
	GENERATED_BODY()
	

public:
	// Constructor
	AJamPlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;

	UFUNCTION(BlueprintCallable)
	FPlayerSave GetCharacterSaveData();

	UFUNCTION(BlueprintCallable)
	void SetPlayerStateFromSaveData(const FPlayerSave& PlayerSaveData);

	UFUNCTION(BlueprintCallable)
	void Die();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerDataLoaded();

public:
/**
 * Components
 */
	// The main camera for the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USpringArmComponent> SpringArm;
/**
 * References
 */
	// Defines the actor the InteractTrace hits
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	AActor* LookAtActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	AJamPlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	AJamPlayerState* JamPlayerState;
/**
 * Misc
 */
	// Defines how far the line trace will go from the camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractDistance;

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

protected:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	void AddStartupAbilities();

private:
	virtual void InitAbilityActorInfo() override;

	// Function run on tick that will allow actors to be highlighted if we look at them. Simply draws a line out of the camera to a point in front of the player based on where the camera is looking.
	void InteractTrace();
};
