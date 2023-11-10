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

	//BlueprintNativeEvent : 블루프린트에서 이벤트 형태로 생성
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateMyHp(float CurHp, float MaxHp); // OnUpdateMyHp -> 블루프린트에서 사용하는 함수이름, 여기선 cpp 정의 생성하면 안됨

	void OnUpdateMyHp_Implementation(float CurHp, float MaxHp); // OnUpdateMyHp_Implementation -> c++에서 사용하는 함수이름, 그래서 cpp 정의 생성해줄 수 있음

	//BlueprintNativeEvent : 블루프린트에서 이벤트 형태로 생성
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
