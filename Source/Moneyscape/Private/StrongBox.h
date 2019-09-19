// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrongBox.generated.h"

UCLASS()
class AStrongBox : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AStrongBox();

protected:

	virtual void OnConstruction(const FTransform& Transform) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> TargetsPoint;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class APickup>> ActorToSpawn;
};
