// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"// Replicated 처리에서 DOREPLIFETIME 기능을 가지고 있는 라이브러리
#include "GameFramework/SpringArmComponent.h"
#include "GameMode/ShootingHUD.h"


// Sets default values
AWeapon::AWeapon() :m_Ammo(30)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	WeaponMesh->SetCollisionProfileName("OverlapAllDynamic");

	bReplicates = true; // 리플리케이트 켜주기
	SetReplicateMovement(true); // 이동리플리케이트 켜주기

	SetRootComponent(WeaponMesh);
}

// GetLifetimeReplicatedProps: Replicated 변수의 코드를 연결하는 영역
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

	//UGameplayStatics: 언리얼에서 사용하는 대부분의 기능은 여기에 속해있음
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
	// 여기서부터는 vStart, vEnd 값이 계산되어서 들어가있다.
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
	// 참조전달은 .을 찍거나 -> 화살표 두가지 방법, * 포인터가 있을땐 화살표로 끌어온다
	WeaponMesh->SetSimulatePhysics(false);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->AttachToComponent(pChar->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("weapon"));
	UpdateHUD_MyAmmo(m_Ammo);


}

void AWeapon::UseAmmo()
{
	
	m_Ammo = m_Ammo - 1; // m_Ammo -= 1;
	m_Ammo = FMath::Clamp(m_Ammo, 0, 30);// -1이 되었을 때 Ammo값은 0으로
	OnRep_Ammo();
}

void AWeapon::OnRep_Ammo() // MyHp가 업데이트될 때 Event_Dele_UpdateHp가 호출됨
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

	FCollisionQueryParams collisionQuery; // 컬리전 체크 추가 옵션
	collisionQuery.AddIgnoredActor(m_pChar); // 히트 체크시 무시할 액터 추가

	FHitResult result;
	bool itHit = GetWorld()->LineTraceSingleByObjectType(result, vStart, vEnd, collisionObjs, collisionQuery);
	DrawDebugLine(GetWorld(), vStart, vEnd, FColor::Red, false, 5.0f);
	if (itHit == false)
		return;

	ACharacter* pHitChar = Cast<ACharacter> (result.GetActor());
	if (pHitChar == nullptr)// pHitChar가 nullptr이라는 건 result.GetActor()가 캐릭터가 아니다
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

	APlayerController* pPlayer = GetWorld()->GetFirstPlayerController();// Player index 0번
	FVector vCameraLoc = pPlayer->PlayerCameraManager->GetCameraLocation();
	FVector vCameraForward = pPlayer->PlayerCameraManager->GetActorForwardVector();

	vStart = (vCameraForward * (pArm->TargetArmLength + 100)) + vCameraLoc ;
	vEnd = (vCameraForward * 10000) + vCameraLoc;
}

void AWeapon::UpdateHUD_MyAmmo(int Ammo)
{

	APlayerController* pPlayer0 = GetWorld()->GetFirstPlayerController();// 블루프린트에서 Get Player Controller
	if (IsValid(pPlayer0) == false)
		return;
	AController* pOwner = m_pChar->GetController();
	if (pPlayer0 != pOwner)
		return;


	AShootingHUD* pHud = Cast<AShootingHUD>(pPlayer0->GetHUD());//AShootingHUD* pHud = Cast<AShootingHUD>: 형변환, (pPlayer->GetHUD()): 타깃을 HUD로 가져오는것
	if (IsValid(pHud) == false)
		return;


	pHud->OnUpdateMyAmmo(Ammo);

	//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Green,
	//	FString::Printf(TEXT("OnRep_Ammo, Ammo=%f"), Ammo));

	//if (Event_Dele_UpdateHp.IsBound()) // 만약 여기서 바인딩되어 있는 애가 있다면
	//	Event_Dele_UpdateHp.Broadcast(OnRep_Ammo, 100); // 모든 바인딩되어있는 애한테 알려준다 (m_CurHp, 100) 이 두 정보를 포함하여
}

