// Fill out your copyright notice in the Description page of Project Settings.
// 언리얼클래스를 생성하는 기본 규칙
#pragma once

#include "CoreMinimal.h" // 컴파일 속도를 빠르게 하기위해 기본적인 최소한의 라이브러리만 포함한 해더
#include "GameFramework/Actor.h" // AActor 클래스 해더 파일


// **중요** .generated.h 생성 처리하는 해더
// 모든 언리얼 클래스가 생성되려면 아래 코드를 넣어줘야 한다.
// 반드시 모든 #include 마지막에 배치
#include "MoveLeftRight.generated.h" 

UCLASS()// 언리얼 클래스 선언
// 이 클래스는 UNREALCODE_API 모듈에 포함된다.

class UNREALCODE_API AMoveLeftRight : public AActor // public AActor : AActor에 기능 상속 받겠다.
{
	GENERATED_BODY()// 언리얼 코드 생성 함수 - 언리얼 클래스 생성 기본 규칙
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();// 생성자
	~AMoveLeftRight();// 파괴자 / 우클릭 - 빠른작업 및 리팩터링 - 정의만들기(cpp에 생성됨)

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;// override를 쓰면 상속받은 클래스에서 또 한번 수정해서 사용할 수 있다 // virtual을 쓰면 자식한테 상속할 수 있다는 뜻, override가 없는 건 부모클래스

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	// UPROPERTY : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float LocX;
	bool IsMoveRight;
};
