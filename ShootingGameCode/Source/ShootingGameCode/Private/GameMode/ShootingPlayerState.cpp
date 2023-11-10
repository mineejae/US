// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/ShootingPlayerState.h"
#include <Net/UnrealNetwork.h> // DOREPLIFETIME ���� ����

AShootingPlayerState::AShootingPlayerState():m_CurHp(100)
{
}

// GetLifetimeReplicatedProps: Replicated ������ �ڵ带 �����ϴ� ���� �츮�� �� ������ ���â�� ����ְ� ������ ���� ����
// ���ø�����Ʈ �Ǵ� ���ø�����Ʈ��Ƽ�Ǹ��ϴ� �����϶�
void AShootingPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const // AShootingPlayerState: Ŭ���� �̸�
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps); // ������� 2���̱⺻��Ʈ

	DOREPLIFETIME(AShootingPlayerState, m_CurHp); // ���ø�����Ƽ���� �������� �߰��ϴ� ��
}

void AShootingPlayerState::AddDamage(float Damage)
{
	m_CurHp = m_CurHp - Damage;
	OnRep_CurHp();
}

void AShootingPlayerState::OnRep_CurHp() // MyHp�� ������Ʈ�� �� Event_Dele_UpdateHp�� ȣ���
{
	GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, 
		FString::Printf(TEXT("OnRep_CurHp m_CurHp=%f"), m_CurHp));
	
	if (Event_Dele_UpdateHp.IsBound()) // ���� ���⼭ ���ε��Ǿ� �ִ� �ְ� �ִٸ�
		Event_Dele_UpdateHp.Broadcast(m_CurHp, 100); // ��� ���ε��Ǿ��ִ� ������ �˷��ش� (m_CurHp, 100) �� �� ������ �����Ͽ�



}
