// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameplayGameMode.generated.h"

/**
 * 
 */

class UDataTable;

UCLASS()
class MONEYSCAPE_API AGameplayGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:

	UDataTable* GetItemDT() const { return ItemDT; }

protected:

	UPROPERTY(EditDefaultsOnly)
	UDataTable* ItemDT;
};
