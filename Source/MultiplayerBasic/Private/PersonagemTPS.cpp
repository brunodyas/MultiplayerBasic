// Fill out your copyright notice in the Description page of Project Settings.


#include "PersonagemTPS.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Construtor
APersonagemTPS::APersonagemTPS()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup Camera
	SpringArmCamera = CreateDefaultSubobject<USpringArmComponent>(FName("SpringArmCamera"));
	SpringArmCamera->TargetArmLength = 200.f;
	SpringArmCamera->bUsePawnControlRotation = true;
	SpringArmCamera->AddRelativeLocation(FVector(0.f,40.f,50.f));
	SpringArmCamera->SetupAttachment(RootComponent);

	CameraPersonagem = CreateDefaultSubobject<UCameraComponent>(FName("CameraPersonagem"));
	CameraPersonagem->SetupAttachment(SpringArmCamera);

	// Auto possess
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
}

// Called when the game starts or when spawned
void APersonagemTPS::BeginPlay()
{
	Super::BeginPlay();
	
}

void APersonagemTPS::MoverParaFrente(float Valor)
{
	AddMovementInput(GetActorForwardVector() * Valor);
}

void APersonagemTPS::MoverDireita(float Valor)
{
	AddMovementInput(GetActorRightVector() * Valor);
}

// Called every frame
void APersonagemTPS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APersonagemTPS::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoverParaFrente", this, &APersonagemTPS::MoverParaFrente);
	PlayerInputComponent->BindAxis("MoverDireita", this, &APersonagemTPS::MoverDireita);
	PlayerInputComponent->BindAxis("OlharCimaBaixo", this, &APersonagemTPS::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("OlharEsquerdaDireita", this, &APersonagemTPS::AddControllerYawInput);
}	

