// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingHUD.h"
#include "Blueprint/UserWidget.h"
#include "GameMode/ShootingPlayerState.h"

void AShootingHUD::BeginPlay()
{
	Super::BeginPlay();

	//if (IsValid(HudWidgetClass) == false)
	// return;
	check(HudWidgetClass);// check : check ()안에 객체가 비정상적이면 죽는다.

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget-> AddToViewport();

	BindMyPlayerState(); // 마지막에 호출해주기
}

void AShootingHUD::BindMyPlayerState()
{
	APlayerController* pPC = Cast<APlayerController>(GetWorld() -> GetFirstPlayerController());

	if (IsValid(pPC))
	{
		AShootingPlayerState* pPS = Cast<AShootingPlayerState>(pPC->PlayerState);
		if (IsValid(pPS))
		{
			pPS->Event_Dele_UpdateHp.AddDynamic(this, &AShootingHUD::OnUpdateMyHp); //  디스패쳐에 바인딩 하는 것).AddDynamic : 바인딩(=인스타 팔로우, 인플루언서가 포스팅하면 바로 볼 수 있는)해주는 기능
			OnUpdateMyHp(pPS->m_CurHp, 100); // HP 프로그레스바를 기본값을 100으로
			return; // 끝나고 타이머가 돌면 안되니 반환처리
		}
	}

	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	timerManager.SetTimer(th_BindMyPlayerState, this, &AShootingHUD::BindMyPlayerState, 0.01f, false);

}

void AShootingHUD::OnUpdateMyHp_Implementation(float CurHp, float MaxHp) 
{
}

void AShootingHUD::OnUpdateMyAmmo_Implementation(int Ammo)
{
}
