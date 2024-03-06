// Fill out your copyright notice in the Description page of Project Settings.


#include "myperso.h"

#include "Components/CapsuleComponent.h"

// Sets default values
Amyperso::Amyperso()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("Init Perso"));

	// Capsule

	GetCapsuleComponent()->SetCapsuleSize(25.8f,92.2f);



	// Skeleta

	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshObj(TEXT("SkeletalMesh'/Game/PN_OpenWorldFoliage/UE4_ThirdPerson/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
		if (MeshObj.Object)
		{
			GetMesh()->SetSkeletalMesh(MeshObj.Object);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Erreur Mesh"))
		}


	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));




}

// Called when the game starts or when spawned
void Amyperso::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Warning, TEXT("Launch Perso"));

	
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

