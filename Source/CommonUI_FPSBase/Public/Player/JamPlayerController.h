// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Data/SaveGameStructs.h"
#include "JamPlayerController.generated.h"

class UJamInputConfig;
class UJamAbilitySystemComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API AJamPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

public:
	// Constructor
	AJamPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class APawn* PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class ACharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Input)
	bool InvertY;

	// A reference to the character's ability system component, set when GetJamASC is called
	UPROPERTY()
	TObjectPtr<UJamAbilitySystemComponent> JamAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
	AJamPlayerState* JamPlayerState;

protected:
	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	virtual void BeginPlay() override;

	/** Called for movement input */
	UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	UFUNCTION(BlueprintCallable)
	void Look(const FInputActionValue& Value);

	virtual void PostInitializeComponents() override; // Overridden to create a reference to the player state at the earliest possible time

	// APawn interface
	void SetupInputComponent(UInputComponent* InputComponent);
	// End of APawn interface

public:

	// Sets player controller's current controls equal to the controls found in the save data
	UFUNCTION(BlueprintCallable)
	void SetControlsFromSaveData(const FControlsSave& ControlsSaveData);

	// Helper function that retrieves our custom JamAbilitySystemComponent
	UFUNCTION(BlueprintCallable)
	UJamAbilitySystemComponent* GetJamASC();

private:
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UJamInputConfig> InputConfig;
};
