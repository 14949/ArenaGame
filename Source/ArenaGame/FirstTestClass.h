// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class ARENAGAME_API FirstTestClass
{
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Test")
		int32 testNumber;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Test")
		int32 testNumber2;
	FirstTestClass();
	~FirstTestClass();
};
