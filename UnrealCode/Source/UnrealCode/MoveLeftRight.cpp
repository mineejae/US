// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"

// Sets default values
AMoveLeftRight::AMoveLeftRight() : LocX(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//CreateDefaultSubobject : new 키워드와 같이 언리얼에서 동적으로 객체를 생성하는 키워드
	//TEXT : 언리얼에서 사용하는 문자형 중에 하나
	//<USceneComponent>(TEXT("SceneRootRoot")); // USceneComponent를 "SceneRootRoot" 이름으로 동적으로 생성
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	//<UStaticMeshComponent>(TEXT("mymyMesh")); // UStaticMeshComponent객체를 "mymyMesh" 이름으로 동적으로 생성
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene); // Scene을 Root Componet로 올리겠다.
	//SetRootComponent = Scene;//똑같은 처리// Scene을 Root Componet로 올리겠다.

	//AttachToComponent : Componet 붙이는 기능
	//Scene에 붙인다, 현재 좌표값을 Scene 기준에 Relative(상대) 좌표계로
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	//RootComponent에 붙인다, 현재 좌표값을 RootComponent 기준에 Relative(상대) 좌표계로
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	// .은 레퍼런스로 참조 ->는 포인터로 참조

	// UAsset 가져오기
	// ConstructorHelpers::FObjectFinder : 오브젝트 에셋을 찾는다.
	// <UStaticMesh> : 찾을 에셋 타입 // 이건 컴포넌트가 아님 컴포넌트에 넣을 에셋
	// sm : 찾아서 넣을 객체 이름
	// 언리얼가서 에셋 우클릭 레퍼런스 복사 "" 안에 복붙
	
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	if (sm.Succeeded()) // 에셋 불러오기 성공 여부 체크
	{
		StaticMesh->SetStaticMesh(sm.Object);// StaticMeshComponent에 StaticMesh 적용
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
	Super::Tick(DeltaTime); // 오버라이드한 함수인 경우 부모 함수를 실행한다. Super: 부모
	
	//IsMoveRight;// 움직일 방향

	//LocX += 1;// 오른쪽
	//
	//LocX -= 1;// 왼쪽

	// SetRelativeLocation : 상대적인 위치값을 설정한다.
	// FVector : 언리얼에서 사용하는 3차원 좌표 변수
	StaticMesh->SetRelativeLocation(FVector(LocX,0,0));

	

	if (IsMoveRight) // 블루프린트 내에서 Branch 역할
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

