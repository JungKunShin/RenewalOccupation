// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerController/C_BasePlayerController.h"
#include "C_WorldPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API AC_WorldPlayerController : public AC_BasePlayerController
{
	GENERATED_BODY()
	
public:
	AC_WorldPlayerController();

protected:
	virtual void SetupInputComponent() override;

	void MapChecking();

	void PauseOpen();

	virtual void InitSound()override;

	void DelaySound();

private:
	bool IsMap = false;

	bool IsPause = false;

	FTimerHandle SoundTH;
};
