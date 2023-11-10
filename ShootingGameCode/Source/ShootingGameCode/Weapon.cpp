// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"// Replicated ó������ DOREPLIFETIME ����� ������ �ִ� ���̺귯��
#include "GameFramework/SpringArmComponent.h"
#include "GameMode/ShootingHUD.h"


// Sets default values
AWeapon::AWeapon() :m_Ammo(30)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	WeaponMesh->SetCollisionProfileName("OverlapAllDynamic");

	bReplicates = true; // ���ø�����Ʈ ���ֱ�
	SetReplicateMovement(true); // �̵����ø�����Ʈ ���ֱ�

	SetRootComponent(WeaponMesh);
}

// GetLifetimeReplicatedProps: Replicated ������ �ڵ带 �����ϴ� ����
void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeapon, m_pChar);
	DOREPLIFETIME(AWeapon, m_Ammo);

}


// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::EventTrigger_Implementation()
{
	if (IsValid(ShootMontage) == false)
		return;

	m_pChar->PlayAnimMontage(ShootMontage);

}

void AWeapon::EventShoot_Implementation()
{
	if (FireEffect == nullptr)
		return;

	//UGameplayStatics: �𸮾󿡼� ����ϴ� ��κ��� ����� ���⿡ ��������
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), FireEffect, 
		WeaponMesh->GetSocketLocation("muzzle"),
		WeaponMesh->GetSocketRotation("muzzle"),
		FVector(0.2f, 0.2f, 0.2f));

	ACharacter* pPlayer0 =  UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (pPlayer0 != m_pChar)
		return;

	FVector vStart;
	FVector vEnd;
	CalcShootStartEndPos(vStart, vEnd);
	// ���⼭���ʹ� vStart, vEnd ���� ���Ǿ ���ִ�.
	//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, TEXT("(Client)ReqSReqApplyDamage"));
	ReqApplyDamage(vStart, vEnd);

}

void AWeapon::EventDrop_Implementation(ACharacter* pChar)
{
	UpdateHUD_MyAmmo(0);
	m_pChar = nullptr;
	WeaponMesh->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	WeaponMesh->SetSimulatePhysics(true);
	SetOwner(nullptr);
}


void AWeapon::EventPickup_Implementation(ACharacter* pChar)
{
	m_pChar = pChar; 
	// ���������� .�� ��ų� -> ȭ��ǥ �ΰ��� ���, * �����Ͱ� ������ ȭ��ǥ�� ����´�
	WeaponMesh->SetSimulatePhysics(false);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->AttachToComponent(pChar->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("weapon"));
	UpdateHUD_MyAmmo(m_Ammo);


}

void AWeapon::UseAmmo()
{
	
	m_Ammo = m_Ammo - 1; // m_Ammo -= 1;
	m_Ammo = FMath::Clamp(m_Ammo, 0, 30);// -1�� �Ǿ��� �� Ammo���� 0����
	OnRep_Ammo();
}

void AWeapon::OnRep_Ammo() // MyHp�� ������Ʈ�� �� Event_Dele_UpdateHp�� ȣ���
{
	UpdateHUD_MyAmmo(m_Ammo);
}

void AWeapon::ReqApplyDamage_Implementation(FVector vStart, FVector vEnd)
{
	
	
	UseAmmo();

	//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green, TEXT("(Server)ReqSReqApplyDamage"));
	
	FCollisionObjectQueryParams collisionObjs;
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_PhysicsBody);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_Vehicle);
	collisionObjs.AddObjectTypesToQuery(ECollisionChannel::ECC_Destructible);

	FCollisionQueryParams collisionQuery; // �ø��� üũ �߰� �ɼ�
	collisionQuery.AddIgnoredActor(m_pChar); // ��Ʈ üũ�� ������ ���� �߰�

	FHitResult result;
	bool itHit = GetWorld()->LineTraceSingleByObjectType(result, vStart, vEnd, collisionObjs, collisionQuery);
	DrawDebugLine(GetWorld(), vStart, vEnd, FColor::Red, false, 5.0f);
	if (itHit == false)
		return;

	ACharacter* pHitChar = Cast<ACharacter> (result.GetActor());
	if (pHitChar == nullptr)// pHitChar�� nullptr�̶�� �� result.GetActor()�� ĳ���Ͱ� �ƴϴ�
		return;

	UGameplayStatics::ApplyDamage(pHitChar, 10.0f, m_pChar->GetController(), this, UDamageType::StaticClass());
}



void AWeapon::CalcShootStartEndPos(FVector& vStart, FVector& vEnd)
{
	if (IsValid(m_pChar) == false)
	return;

	USpringArmComponent* pArm = Cast<USpringArmComponent>(m_pChar->GetComponentByClass(USpringArmComponent::StaticClass()));
	if (IsValid(pArm) == false)
		return;

	APlayerController* pPlayer = GetWorld()->GetFirstPlayerController();// Player index 0��
	FVector vCameraLoc = pPlayer->PlayerCameraManager->GetCameraLocation();
	FVector vCameraForward = pPlayer->PlayerCameraManager->GetActorForwardVector();

	vStart = (vCameraForward * (pArm->TargetArmLength + 100)) + vCameraLoc ;
	vEnd = (vCameraForward * 10000) + vCameraLoc;
}

void AWeapon::UpdateHUD_MyAmmo(int Ammo)
{

	APlayerController* pPlayer0 = GetWorld()->GetFirstPlayerController();// �������Ʈ���� Get Player Controller
	if (IsValid(pPlayer0) == false)
		return;
	AController* pOwner = m_pChar->GetController();
	if (pPlayer0 != pOwner)
		return;


	AShootingHUD* pHud = Cast<AShootingHUD>(pPlayer0->GetHUD());//AShootingHUD* pHud = Cast<AShootingHUD>: ����ȯ, (pPlayer->GetHUD()): Ÿ���� HUD�� �������°�
	if (IsValid(pHud) == false)
		return;


	pHud->OnUpdateMyAmmo(Ammo);

	//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green,
	//	FString::Printf(TEXT("OnRep_Ammo, Ammo=%f"), Ammo));

	//if (Event_Dele_UpdateHp.IsBound()) // ���� ���⼭ ���ε��Ǿ� �ִ� �ְ� �ִٸ�
	//	Event_Dele_UpdateHp.Broadcast(OnRep_Ammo, 100); // ��� ���ε��Ǿ��ִ� ������ �˷��ش� (m_CurHp, 100) �� �� ������ �����Ͽ�
}

