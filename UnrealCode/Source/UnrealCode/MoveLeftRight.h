// Fill out your copyright notice in the Description page of Project Settings.
// �𸮾�Ŭ������ �����ϴ� �⺻ ��Ģ
#pragma once

#include "CoreMinimal.h" // ������ �ӵ��� ������ �ϱ����� �⺻���� �ּ����� ���̺귯���� ������ �ش�
#include "GameFramework/Actor.h" // AActor Ŭ���� �ش� ����


// **�߿�** .generated.h ���� ó���ϴ� �ش�
// ��� �𸮾� Ŭ������ �����Ƿ��� �Ʒ� �ڵ带 �־���� �Ѵ�.
// �ݵ�� ��� #include �������� ��ġ
#include "MoveLeftRight.generated.h" 

UCLASS()// �𸮾� Ŭ���� ����
// �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.

class UNREALCODE_API AMoveLeftRight : public AActor // public AActor : AActor�� ��� ��� �ްڴ�.
{
	GENERATED_BODY()// �𸮾� �ڵ� ���� �Լ� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();// ������
	~AMoveLeftRight();// �ı��� / ��Ŭ�� - �����۾� �� �����͸� - ���Ǹ����(cpp�� ������)

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;// override�� ���� ��ӹ��� Ŭ�������� �� �ѹ� �����ؼ� ����� �� �ִ� // virtual�� ���� �ڽ����� ����� �� �ִٴ� ��, override�� ���� �� �θ�Ŭ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	// UPROPERTY : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float LocX;
	bool IsMoveRight;
};
