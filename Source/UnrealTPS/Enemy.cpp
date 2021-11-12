// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "AIController.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ����� skeletalMesh �����ε�
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin_Female.SK_Mannequin_Female'"));

	if (tempMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
		GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	}

	// ai ��Ʈ�ѷ��� ������ �����ϵ��� ����
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	ai = Cast<AAIController>(GetController());
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// FSM ����
	switch (enemyState)
	{
		case EEnemyState::IDLE:
		{
			IdleState();
			break;
		}
		case EEnemyState::MOVE:
		{
			MoveState();
			break;
		}
		case EEnemyState::ATTACK:
		{
			AttackState();
			break;
		}
		case EEnemyState::DAMAGE:
		{
			DamageState();
			break;
		}
		case EEnemyState::DIE:
		{
			DieState();
			break;
		}
	}
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::IdleState()
{
	// �����ð� ��ٷȴٰ� ���¸� Move �� ��ȯ
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > idleDelayTime)
	{
		currentTime = 0;
		enemyState = EEnemyState::MOVE;
	}
}

void AEnemy::MoveState()
{
	// target ������ �̵��ϰ�ʹ�.
	// 1. ������ �ʿ�. target - me
	FVector dir = target->GetActorLocation() - GetActorLocation();
	float distance = dir.Size();
	dir.Normalize();
	// 2. �̵��ϰ�ʹ�.
	//AddMovementInput(dir);
	
	if (ai)
	{
		ai->MoveToActor(target);
	}

}

void AEnemy::AttackState()
{
}

void AEnemy::DamageState()
{
}

void AEnemy::DieState()
{
}

