// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interactable.h"
#include "MoneyscapeCharacter.h"
#include "GameplayController.generated.h"

/**
 * 
 */
UCLASS()
class MONEYSCAPE_API AGameplayController : public APlayerController
{
	GENERATED_BODY()
	
public:

	//Reloads the players inventory - call this when you've made changes to the players inventory
//and want to see the changes
	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();

	UFUNCTION(BlueprintCallable, Category = "Utils")
	void AddItemToInventoryByID(FName ID);

	////The interactable that the player is currently looking at. This will be equal to nullptr if the player is not looking at something that is interactable.
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	//class AInteractable* CurrentInteractable;

	//UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	//TArray<FInventoryItem> Inventory;

protected:

	void Interact();

	virtual void SetupInputComponent() override;
};
