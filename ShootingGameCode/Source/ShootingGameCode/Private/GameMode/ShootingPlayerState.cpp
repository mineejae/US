// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingPlayerState.h"
#include <Net/UnrealNetwork.h> // DOREPLIFETIME 쓰기 위한

AShootingPlayerState::AShootingPlayerState():m_CurHp(100)
{
}

// GetLifetimeReplicatedProps: Replicated 변수의 코드를 연결하는 영역 우리는 이 정보를 허드창에 띄워주고 싶으니 허드로 ㄱㄱ
// 리플리케이트 또는 리플리케이트노티피를하는 변수일때
void AShootingPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const // AShootingPlayerState: 클래스 이름
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps); // 여기까지 2줄이기본세트

	DOREPLIFETIME(AShootingPlayerState, m_CurHp); // 리플리케이티드할 변수들을 추가하는 줄
}

void AShootingPlayerState::AddDamage(float Damage)
{
	m_CurHp = m_CurHp - Damage;
	OnRep_CurHp();
}

void AShootingPlayerState::OnRep_CurHp() // MyHp가 업데이트될 때 Event_Dele_UpdateHp가 호출됨
{
	GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, 
		FString::Printf(TEXT("OnRep_CurHp m_CurHp=%f"), m_CurHp));
	
	if (Event_Dele_UpdateHp.IsBound()) // 만약 여기서 바인딩되어 있는 애가 있다면
		Event_Dele_UpdateHp.Broadcast(m_CurHp, 100); // 모든 바인딩되어있는 애한테 알려준다 (m_CurHp, 100) 이 두 정보를 포함하여



}
