// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"

// Sets default values
APickup::APickup() {
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");

	ItemID = FName("Please enter an ID");

	bReplicates = true;
}

