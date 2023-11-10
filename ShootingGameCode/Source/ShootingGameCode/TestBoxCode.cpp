// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBoxCode.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Character.h"

// Sets default values
ATestBoxCode::ATestBoxCode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));

	SetRootComponent(Scene);
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Arrow->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	StaticMesh->SetCollisionProfileName("OverlapAllDynamic");

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ATestBoxCode::OnComponentBeginOverlap);

}

// Called when the game starts or when spawned
void ATestBoxCode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestBoxCode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestBoxCode::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* pChar = Cast<ACharacter>(OtherActor);
	if (pChar == nullptr) // null:����, pChar�� ����. ĳ���� ����. �̷��� ������Ѵ�
		return;

	if (IsValid(ActorClass) == false) // ActorClass�� ���� �𸣰�, spawn�� ����� �� �־��� ���¿����� ��ȯó��/ �� ť�갡 �ƴϴ��� ����� ���� �����Ǹ� �����(BP_TestBox�� �ƴ� �ٸ� ����Ŭ�������� �����)
		return;

	if (HasAuthority() == false) // HasAuthority == true �� ������ ����, ������ ���� �� ����
		return;

	AActor* pActor = GetWorld()->SpawnActor<AActor>(ActorClass, Arrow->GetComponentTransform() ); // Arrow ��ġ���� ActorClass�� �������� spawn(����)�Ѵ�.
}

