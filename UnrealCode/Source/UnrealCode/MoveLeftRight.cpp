// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight() : LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//CreateDefaultSubobject : new Ű����� ���� �𸮾󿡼� �������� ��ü�� �����ϴ� Ű����
	//TEXT : �𸮾󿡼� ����ϴ� ������ �߿� �ϳ�
	//<USceneComponent>(TEXT("SceneRootRoot")); // USceneComponent�� "SceneRootRoot" �̸����� �������� ����
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	//<UStaticMeshComponent>(TEXT("mymyMesh")); // UStaticMeshComponent��ü�� "mymyMesh" �̸����� �������� ����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene); // Scene�� Root Componet�� �ø��ڴ�.
	//SetRootComponent = Scene;//�Ȱ��� ó��// Scene�� Root Componet�� �ø��ڴ�.

	//AttachToComponent : Componet ���̴� ���
	//Scene�� ���δ�, ���� ��ǥ���� Scene ���ؿ� Relative(���) ��ǥ���
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	//RootComponent�� ���δ�, ���� ��ǥ���� RootComponent ���ؿ� Relative(���) ��ǥ���
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	// .�� ���۷����� ���� ->�� �����ͷ� ����

	// UAsset ��������
	// ConstructorHelpers::FObjectFinder : ������Ʈ ������ ã�´�.
	// <UStaticMesh> : ã�� ���� Ÿ�� // �̰� ������Ʈ�� �ƴ� ������Ʈ�� ���� ����
	// sm : ã�Ƽ� ���� ��ü �̸�
	// �𸮾󰡼� ���� ��Ŭ�� ���۷��� ���� "" �ȿ� ����
	
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (sm.Succeeded()) // ���� �ҷ����� ���� ���� üũ
	{
		StaticMesh->SetStaticMesh(sm.Object);// StaticMeshComponent�� StaticMesh ����
	}*/
}

AMoveLeftRight::~AMoveLeftRight()
{
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // �������̵��� �Լ��� ��� �θ� �Լ��� �����Ѵ�. Super: �θ�
	
	//IsMoveRight;// ������ ����

	//LocX += 1;// ������
	//
	//LocX -= 1;// ����

	// SetRelativeLocation : ������� ��ġ���� �����Ѵ�.
	// FVector : �𸮾󿡼� ����ϴ� 3���� ��ǥ ����
	StaticMesh->SetRelativeLocation(FVector(LocX,0,0));

	

	if (IsMoveRight) // �������Ʈ ������ Branch ����
	{
		LocX += 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		if(LocX>=200)
		{
			IsMoveRight = false;
		}
	}
	else 
	{
		LocX -= 1;
		StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));
		if (LocX < -200)
		{
			IsMoveRight = true;
		}
	}


}

