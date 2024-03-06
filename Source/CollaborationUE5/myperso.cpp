// Fill out your copyright notice in the Description page of Project Settings.


#include "myperso.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
Amyperso::Amyperso()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("Init Perso"));

	// Capsule

	GetCapsuleComponent()->SetCapsuleSize(25.8f,92.2f);

	// CharacterMouvement

	GetCharacterMovement()->JumpZVelocity = 600.f;

	GetCharacterMovement()->AirControl = 0.2f;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCharacterMovement()->MaxWalkSpeed = 500.f;

	// Skeleta

	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshObj(TEXT("SkeletalMesh'/Game/Importe/PN_OpenWorldFoliage/UE4_ThirdPerson/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
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


	// Set Joueur 1

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Camera

	mySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("mySpringArm"));

	mySpringArm->SetupAttachment(RootComponent);

	mySpringArm->bUsePawnControlRotation = true;

	mySpringArm->TargetArmLength = 776.2f;





	myCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("myCamera"));

	myCamera->SetupAttachment(mySpringArm);


	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;




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


	PlayerInputComponent->BindAxis("MoveY", this, &Amyperso::FunctionMoveY);



	PlayerInputComponent->BindAction("ToRun", IE_Pressed,this, &Amyperso::FunctionToRun);
	PlayerInputComponent->BindAction("ToRun", IE_Released,this, &Amyperso::FunctionNotToRun);

	PlayerInputComponent->BindAction("ToJump", IE_Pressed,this, &Amyperso::FunctionToJump);


}

void Amyperso::FunctionMoveY(float value)
{
	if (Controller && value != 0.0f)
	{
		FRotator rotation = Controller->GetControlRotation();
		FRotator YawRotation(0, rotation.Yaw, 0);
		FVector direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, value);

	}
}

void Amyperso::FunctionToRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 900.f;
}

void Amyperso::FunctionNotToRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

void Amyperso::FunctionToJump()
{
	Jump();
}

