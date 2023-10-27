// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"
#include "Switch.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight():m_LocX(0), m_IsMoveRight(true), m_IsPlay(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// CreateDefaultSubobject : new Ű����� ���� �𸮾󿡼� �������� ��ü�� �����ϴ� Ű����
	// TEXT : �𸮾󿡼� ����ϴ� ������ �߿� �ϳ�
	// <USceneComponent>(TEXT("SceneRootRoot")) // USceneComponent��ü�� "SceneRootRoot" �̸����� �������� ����
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	// <UStaticMeshComponent>(TEXT("mymyMesh")) // UStaticMeshComponent��ü�� "mymyMesh" �̸����� �������� ����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);// Scene�� Root Component�� �ø��ڴ�.
	//RootComponent = Scene;// Scene�� Root Component�� �ø��ڴ�.

	// AttachToComponent : Component ���̴� ���
	// Scene�� ���δ�, ���� ��ǥ���� Scene ���ؿ� Relative(���) ��ǥ���
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	// RootComponent�� ���δ�, ���� ��ǥ���� RootComponent ���ؿ� Relative(���) ��ǥ���
	// StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// UAsset ��������
	// ConstructorHelpers::FObjectFinder : ������Ʈ ������ ã�´�.
	// <UStaticMesh> : ã�� ���� Ÿ��
	// sm : ã�Ƽ� ���� ��ü �̸�
	/*
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (sm.Succeeded())// ���� �ҷ����� ���� ���� äũ
	{
		StaticMesh->SetStaticMesh(sm.Object);// StaticMeshComponent�� StaticMesh ����
	}
	*/
}

AMoveLeftRight::~AMoveLeftRight()
{
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(m_Switch))
		m_Switch->FDele_EventOverlap.AddDynamic(this, &AMoveLeftRight::EventOverlap);// �̺�Ʈ������ ���ε� ó�� AddDynamic : ���ε��Ѵٴ� �Լ�  
	// m_Switch�� �ִ� FDele_EventOverlap�� ���ε��� �ϰڴ�. ( �� Ŭ������ �ִ� &AMoveLeftRight::EventOverlap �� �Լ���)
}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);// �������̵��� �Լ��� ��� �θ� �Լ��� �����Ѵ�. 

	if (m_IsPlay == false)
		return;

	if (m_IsMoveRight)// ������ ����
	{
		m_LocX += 1;// ������

		// SetRelativeLocation : ������� ��ġ���� �����Ѵ�.
		// FVector : �𸮾󿡼� ����ϴ� 3���� ��ǥ ����
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));

		if (m_LocX >= 200)
		{
			m_IsMoveRight = false;
		}
	}
	else
	{
		m_LocX -= 1;// ����

		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));

		if (m_LocX <= 0)
		{
			m_IsMoveRight = true;
		}
	}
}

void AMoveLeftRight::EventOverlap(bool isBegin)
{
	m_IsPlay = isBegin;
}

void AMoveLeftRight::Code_DoPlay_Implementation(bool IsPlay)
{
	m_IsPlay = IsPlay;
}

