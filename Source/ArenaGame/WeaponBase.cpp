// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CanFire = true;
	CheckRate = 0.1f;
	DynCooldown = CooldownTime;
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::Fire_Implementation()
{

}

// Function for starting the cooldown
void AWeaponBase::StartCooldown()
{
	CanFire = false;
	DynCooldown = CooldownTime;
	GetWorldTimerManager().SetTimer(CooldownTimerHandle, this, &AWeaponBase::AdvanceCooldown, CheckRate, true);
}
// Function for advancing the timer
void AWeaponBase::AdvanceCooldown() 
{
	DynCooldown -= CheckRate;
	FString FloatStr = FString::SanitizeFloat(DynCooldown);
	if (GEngine && DebugPrintOnScreen)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FloatStr);
	if (DynCooldown < CheckRate) 
	{
		GetWorldTimerManager().ClearTimer(CooldownTimerHandle);
		CooldownFinished();
	}
}
// Function for what happens when the cooldown is over
void AWeaponBase::CooldownFinished()
{
	CanFire = true;
}

