// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerController/C_BasePlayerController.h"
#include "C_TitlePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API AC_TitlePlayerController : public AC_BasePlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay()override;

	virtual void InitSound()override;

	void DelayTitleSound();

private:
	FTimerHandle SoundTH;
	
};
