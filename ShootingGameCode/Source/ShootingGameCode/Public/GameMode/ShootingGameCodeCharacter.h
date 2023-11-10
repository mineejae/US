// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Iteminteraction.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ShootingGameCodeCharacter.generated.h"


UCLASS(config=Game)
class AShootingGameCodeCharacter : public ACharacter, public IItemInteraction
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction; // 두줄이 세트 따로 띄어놓으면 안돼

	/** Test Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* TestAction;

	/** Test Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ReloadAction; // IA Reload가 들어갈 칸이 생성되는 기능

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true")) // ShootingCharacter에 칸 생기게 하는 작업
	class UInputAction* ShootAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PressFAction; // 블루프린트에서 캐릭터에 입력값에 액션넣어줄 빈칸 만들어주는 세팅 // 1번

public:
	AShootingGameCodeCharacter();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutlifetimeProps) const;
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for looking input */
	void Test(const FInputActionValue& Value);

	/** Called for looking input */
	void Reload(const FInputActionValue& Value);

	/** Called for looking input */
	void Shoot(const FInputActionValue& Value);

	/** Called for looking input */
	void PressF(const FInputActionValue& Value); // 키입력했을때 호출되는 함수 // 2번

	

	
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

	/**
	 * Apply damage to this actor.
	 * @see https://www.unrealengine.com/blog/damage-in-ue4
	 * @param DamageAmount		How much damage to apply
	 * @param DamageEvent		Data package that fully describes the damage received.
	 * @param EventInstigator	The Controller responsible for the damage.
	 * @param DamageCauser		The Actor that directly caused the damage (e.g. the projectile that exploded, the rock that landed on you)
	 * @return					The amount of damage actually applied.
	 */
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

public:
	// https://docs.unrealengine.com/4.27/ko/InteractiveExperiences/Networking/Actors/RPCs/
	// Sever : 서버에서 실행
	// Reliable은 신뢰성
	// 커스텀이벤트로 리플리케이트하는 방법
	UFUNCTION(Server, Reliable)
	void ReqTestMsg();

	// NetMulticast : 모두에서 실행
	UFUNCTION(NetMulticast, Reliable)
	void ResTestMsg();

	// Client : 소유중인 클라이언트에서 실행
	UFUNCTION(Client, Reliable)
	void ResTestMsgToOwner();


	UFUNCTION(Server, Reliable)
	void ReqReload();

	// NetMulticast : 모두에서 실행
	UFUNCTION(NetMulticast, Reliable)
	void ResReload();

	UFUNCTION(Server, Reliable)
	void ReqShoot();

	// NetMulticast : 모두에서 실행
	UFUNCTION(NetMulticast, Reliable)
	void ResShoot();

	UFUNCTION(Server, Reliable)
	void ReqPressF();

	UFUNCTION(NetMulticast, Reliable)
	void ResPressF(AActor* EquipActor);


public:
	UFUNCTION(BlueprintCallable)
	void TestWeaponSpawn(TSubclassOf<class AWeapon> WeaponClass); // 부모 클래스가 Weapon이어야 한다.
																  // (C++폴더에서 weapon 파생 클래스 생성하거나, 블루프린트 생성에 들어가서 weapon을 검색해서 생성
																  // 혹은 클래스 세팅에 들어가서 디테일에 부모클래스를 바꿔주면 된다.

	void UpdateBindTestWeapon();

	void EventEquip(AActor* pActor);

	void EventUnEquip();

public:

	UPROPERTY(Replicated)
	FRotator m_LookAtRotation;

	UFUNCTION(BlueprintPure)// 블루프린트에서 호출이 가능하게 해줌
	FRotator GetLookAtRotation() { return m_LookAtRotation; };// GetLookAtRotation라는 함수를 만듦, FRotator로 반환을 해주는 함수

	UPROPERTY(Replicated, BlueprintReadWrite)
	AActor* m_pEquipWeapon;

	FTimerHandle th_BindTestWeapon;

	UFUNCTION(BlueprintPure)
	AActor* GetNearestActor();
};

