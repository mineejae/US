// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShootingHUD.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTINGGAMECODE_API AShootingHUD : public AHUD
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	void BindMyPlayerState();

	//BlueprintNativeEvent : �������Ʈ���� �̺�Ʈ ���·� ����
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateMyHp(float CurHp, float MaxHp); // OnUpdateMyHp -> �������Ʈ���� ����ϴ� �Լ��̸�, ���⼱ cpp ���� �����ϸ� �ȵ�

	void OnUpdateMyHp_Implementation(float CurHp, float MaxHp); // OnUpdateMyHp_Implementation -> c++���� ����ϴ� �Լ��̸�, �׷��� cpp ���� �������� �� ����

	//BlueprintNativeEvent : �������Ʈ���� �̺�Ʈ ���·� ����
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateMyAmmo(int Ammo);

	void OnUpdateMyAmmo_Implementation(int Ammo);
	//pHud->OnUpdateMyAmmo(Ammo);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget>HudWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	UUserWidget* HudWidget;

	FTimerHandle th_BindMyPlayerState;
};
