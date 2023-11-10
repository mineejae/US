// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingHUD.h"
#include "Blueprint/UserWidget.h"
#include "GameMode/ShootingPlayerState.h"

void AShootingHUD::BeginPlay()
{
	Super::BeginPlay();

	//if (IsValid(HudWidgetClass) == false)
	// return;
	check(HudWidgetClass);// check : check ()�ȿ� ��ü�� ���������̸� �״´�.

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget-> AddToViewport();

	BindMyPlayerState(); // �������� ȣ�����ֱ�
}

void AShootingHUD::BindMyPlayerState()
{
	APlayerController* pPC = Cast<APlayerController>(GetWorld() -> GetFirstPlayerController());

	if (IsValid(pPC))
	{
		AShootingPlayerState* pPS = Cast<AShootingPlayerState>(pPC->PlayerState);
		if (IsValid(pPS))
		{
			pPS->Event_Dele_UpdateHp.AddDynamic(this, &AShootingHUD::OnUpdateMyHp); //  �����Ŀ� ���ε� �ϴ� ��).AddDynamic : ���ε�(=�ν�Ÿ �ȷο�, ���÷�𼭰� �������ϸ� �ٷ� �� �� �ִ�)���ִ� ���
			OnUpdateMyHp(pPS->m_CurHp, 100); // HP ���α׷����ٸ� �⺻���� 100����
			return; // ������ Ÿ�̸Ӱ� ���� �ȵǴ� ��ȯó��
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
