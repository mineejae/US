// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" // 컴파일 속도를 빠르게 하기위해 기본적인 최소한에 라이브러리만 포함한 해더
#include "Public/Tools/InterfacePlayObj.h"// 경로를 다 적어줘야함(폴더구조) 이게 인터페이스를 통한 형변환 간소화의 핵심!
#include "GameFramework/Actor.h"// AActor 클래스 해더 파일

// *.generated.h 언리얼 클래스 생성 처리하는 해더 - 언리얼 클래스 생성 기본 규칙
// 모든 언리얼 클래스가 생성되려면 아래 코드를 넣어줘야 한다.
// 반드시 모든 #include 마지막에 배치 
#include "MoveLeftRight.generated.h"

// UNREALCODE_API : 이 클래스는 UNREALCODE_API 모듈에 포함된다.
UCLASS()// 언리얼 클래스 선언 - 언리얼 클래스 생성 기본 규칙
class UNREALCODE_API AMoveLeftRight : public AActor, public IInterfacePlayObj//(C++에서는 상속 여러개 받을 수 있음)// public AActor : AActor에 기능 상속 받겠다.
{
	GENERATED_BODY()// 언리얼 코드 생성 함수 - 언리얼 클래스 생성 기본 규칙
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();
	~AMoveLeftRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()//바인드 함수는 반드시 유펑션으로 만들어야함
		void EventOverlap(bool isBegin);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent) // 언리얼함수 블루프린트에서 부를 수 있다, void Code_DoPlay 요 함수를 블루프린트내에서 상속해와서 재구현을 할 수 있다. 상속재구현함수처리 
	void Code_DoPlay(bool IsPlay);//블루프린트 호출용 함수명 선언

	virtual void Code_DoPlay_Implementation(bool IsPlay) override;// c++에서 실행될 함수

public:


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	// UPROPERTY : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float m_LocX;
	bool m_IsMoveRight;
	bool m_IsPlay;
	


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<class ASwitch> m_Switch;
};
