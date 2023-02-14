// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "WeaponBase.generated.h"

UCLASS()
class ARENAGAME_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

// Interface stuff
public:
	UPROPERTY(BlueprintReadWrite)
		AActor* Player;
	UPROPERTY(BlueprintReadWrite)
		UCameraComponent* PlayerCam;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon Base")
		void Fire();

// Cooldown stuff
public:
	UPROPERTY(EditAnywhere)
		float CooldownTime;
	UPROPERTY(EditAnywhere)
		bool DebugPrintOnScreen;
	UPROPERTY(BlueprintReadOnly)
		bool CanFire;

	float DynCooldown;
	float CheckRate;
	FTimerHandle CooldownTimerHandle;

	UFUNCTION(BlueprintCallable, Category = "Weapon Base")
	void StartCooldown();

	void AdvanceCooldown();
	void CooldownFinished();


};
