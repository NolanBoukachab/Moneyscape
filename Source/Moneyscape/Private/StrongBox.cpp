// Fill out your copyright notice in the Description page of Project Settings.

#include "StrongBox.h"
#include "Engine/World.h"
#include "Pickup.h"
#include "Containers/Array.h"

// Sets default values
AStrongBox::AStrongBox() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
}

void AStrongBox::OnConstruction(const FTransform & Transform) {

}

// Called when the game starts or when spawned
void AStrongBox::BeginPlay() {
	Super::BeginPlay();

	if (HasAuthority()) {
		FActorSpawnParameters SpawnParams;

		if (TargetsPoint.Num() == ActorToSpawn.Num()) {
			int j = 0;

			for (int i = 0; i < TargetsPoint.Num(); i++) {
				j = i + FMath::Rand() % TargetsPoint.Num() - i;
				TargetsPoint.Swap(i, j);
			}

			for (int i = 0; i < ActorToSpawn.Num(); i++) {
				APickup* ActorRef = GetWorld()->SpawnActor<APickup>(ActorToSpawn[i], TargetsPoint[i]->GetTransform(), SpawnParams);
			}
		}
	}
}

// Called every frame
void AStrongBox::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

