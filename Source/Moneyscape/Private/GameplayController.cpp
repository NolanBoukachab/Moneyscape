// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayController.h"
#include "GameplayGameMode.h"
#include "Interactable.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "MoneyscapeCharacter.h"

void AGameplayController::AddItemToInventoryByID(FName ID) {

	AGameplayGameMode* GameMode = Cast<AGameplayGameMode>(GetWorld()->GetAuthGameMode());
	UE_LOG(LogTemp, Warning, TEXT("GameMode : %s "), GameMode);

	if (!GameMode) {
		UE_LOG(LogTemp, Warning, TEXT("GameMode : %s "), GetWorld()->GetAuthGameMode());
		return;
	}

	UDataTable* ItemTable = GameMode->GetItemDT();

	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");
	if (ItemToAdd) {
		//Inventory.Add(*ItemToAdd);

		AMoneyscapeCharacter* Character = Cast<AMoneyscapeCharacter>(GetLocalPlayer());
		if (!Character) {
			UE_LOG(LogTemp, Warning, TEXT("Ca plante.."));
			return;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Character : %s "), Character);
			Character->Inventory.Add(*ItemToAdd);
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ItemToAdd : %s "), ItemToAdd);
	}
}

void AGameplayController::Interact() {
	AMoneyscapeCharacter* Character = Cast<AMoneyscapeCharacter>(GetCharacter());
	if (!Character)
		return;

	if (Character->CurrentInteractable) {
		Character->CurrentInteractable->Interact(this);
	}
}

void AGameplayController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &AGameplayController::Interact);
}
