// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFire.h"
#include "UnrealTPSCharacter.h"

// Sets default values for this component's properties
UPlayerFire::UPlayerFire()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bWantsInitializeComponent = true;
	// ...
}


// Called when the game starts
void UPlayerFire::BeginPlay()
{
	Super::BeginPlay();

	
}


void UPlayerFire::InitializeComponent()
{
	Super::InitializeComponent();

	// 컴포넌트에서 델리게이트에 자신을 등록하기
	auto player = Cast<AUnrealTPSCharacter>(GetOwner());

	player->OnPlayerInputEvent.AddUObject(this, &UPlayerFire::SetupPlayerInputComponent);
}

// Called every frame
void UPlayerFire::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerFire::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerFire::Fire);
}


void UPlayerFire::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire!!!!!!!!!!!!!!!!!"));
}

