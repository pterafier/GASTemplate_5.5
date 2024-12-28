// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "JamPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/*
* The ability system component pointers are setup on AuraCharacterBase. This means that Aura and all enemies will have pointers to the ability system component. HOWEVER, Aura's ACTUAL ability system component and attributes
* are setup and initialized on the PlayerState.
* 
* We included the IAbilitySystemInterface as a getter for the ability system component, this simply returns the ability system component. We have done the same thing for GetAttributeSet() except it's not from an interface. 
* This also should be done on the base class so all characters in the world can return the ASC. It needed to be added to this class because Aura's ASC lives on the PlayerState
* 
* For the setup of future ability system components, inherit from the ability system interface and create the attributeset getter function. 
*
* The ability system component has 2 variables for setting owners - the OwnerActor and AvatarActor. If the ability system component is on the character, then the AvatarActor is also the OwnerActor.
* But if it's on the PlayerState (Or another entity) the OwnerActor is the PlayerState, but the AvatarActor is character. Set with InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
* The ability system component needs to be initialized with these actors - more info https://www.udemy.com/course/unreal-engine-5-gas-top-down-rpg/learn/lecture/39782798#questions
* InitAbilityActorInfo must be called after possession (the Controller has been set for the Pawn)
* If the ASC lives on the pawn, call InitAbilityActorInfo in PossessedBy() on the server, and AcknowledgePossession() on the Client
* If the ASC lives on the PlayerState, call InitAbilityActorInfo in PossessedBy() on the Server, and OnRep_PlayerState on the Client
* If the ASC lives on the pawn and is AI-Controlled, simply call InitAbilityActorInfo on BeginPlay()
* 
* Console command showdebug abilitysystem shows debug info about the ability system
*/


/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API AJamPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:

	// Constructor
	AJamPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
