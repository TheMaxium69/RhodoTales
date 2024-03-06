// Fill out your copyright notice in the Description page of Project Settings.


#include "myperso.h"

// Sets default values
Amyperso::Amyperso()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Amyperso::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Amyperso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Amyperso::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

