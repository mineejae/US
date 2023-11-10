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
	if (pChar == nullptr) // null:없다, pChar가 없다. 캐스팅 실패. 이럴때 실행안한다
		return;

	if (IsValid(ActorClass) == false) // ActorClass가 뭔지 모르고, spawn할 대상값이 안 주어진 상태에서는 반환처리/ 꼭 큐브가 아니더라도 대상할 값이 설정되면 실행됨(BP_TestBox가 아닌 다른 액터클래스여도 적용됨)
		return;

	if (HasAuthority() == false) // HasAuthority == true 면 서버만 실행, 권한을 갖는 건 서버
		return;

	AActor* pActor = GetWorld()->SpawnActor<AActor>(ActorClass, Arrow->GetComponentTransform() ); // Arrow 위치에서 ActorClass가 떨어지게 spawn(생성)한다.
}

