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
	class UInputAction* LookAction; // ������ ��Ʈ ���� �������� �ȵ�

	/** Test Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* TestAction;

	/** Test Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ReloadAction; // IA Reload�� �� ĭ�� �����Ǵ� ���

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true")) // ShootingCharacter�� ĭ ����� �ϴ� �۾�
	class UInputAction* ShootAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PressFAction; // �������Ʈ���� ĳ���Ϳ� �Է°��� �׼ǳ־��� ��ĭ ������ִ� ���� // 1��

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
	void PressF(const FInputActionValue& Value); // Ű�Է������� ȣ��Ǵ� �Լ� // 2��

	

	
			

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
	// Sever : �������� ����
	// Reliable�� �ŷڼ�
	// Ŀ�����̺�Ʈ�� ���ø�����Ʈ�ϴ� ���
	UFUNCTION(Server, Reliable)
	void ReqTestMsg();

	// NetMulticast : ��ο��� ����
	UFUNCTION(NetMulticast, Reliable)
	void ResTestMsg();

	// Client : �������� Ŭ���̾�Ʈ���� ����
	UFUNCTION(Client, Reliable)
	void ResTestMsgToOwner();


	UFUNCTION(Server, Reliable)
	void ReqReload();

	// NetMulticast : ��ο��� ����
	UFUNCTION(NetMulticast, Reliable)
	void ResReload();

	UFUNCTION(Server, Reliable)
	void ReqShoot();

	// NetMulticast : ��ο��� ����
	UFUNCTION(NetMulticast, Reliable)
	void ResShoot();

	UFUNCTION(Server, Reliable)
	void ReqPressF();

	UFUNCTION(NetMulticast, Reliable)
	void ResPressF(AActor* EquipActor);


public:
	UFUNCTION(BlueprintCallable)
	void TestWeaponSpawn(TSubclassOf<class AWeapon> WeaponClass); // �θ� Ŭ������ Weapon�̾�� �Ѵ�.
																  // (C++�������� weapon �Ļ� Ŭ���� �����ϰų�, �������Ʈ ������ ���� weapon�� �˻��ؼ� ����
																  // Ȥ�� Ŭ���� ���ÿ� ���� �����Ͽ� �θ�Ŭ������ �ٲ��ָ� �ȴ�.

	void UpdateBindTestWeapon();

	void EventEquip(AActor* pActor);

	void EventUnEquip();

public:

	UPROPERTY(Replicated)
	FRotator m_LookAtRotation;

	UFUNCTION(BlueprintPure)// �������Ʈ���� ȣ���� �����ϰ� ����
	FRotator GetLookAtRotation() { return m_LookAtRotation; };// GetLookAtRotation��� �Լ��� ����, FRotator�� ��ȯ�� ���ִ� �Լ�

	UPROPERTY(Replicated, BlueprintReadWrite)
	AActor* m_pEquipWeapon;

	FTimerHandle th_BindTestWeapon;

	UFUNCTION(BlueprintPure)
	AActor* GetNearestActor();
};

