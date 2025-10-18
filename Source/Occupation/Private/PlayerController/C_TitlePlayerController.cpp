// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/C_TitlePlayerController.h"
#include "Manager/C_SoundManager.h"

void AC_TitlePlayerController::BeginPlay()
{
	GetWorld()->GetTimerManager().ClearTimer(SoundTH);
	GetWorld()->GetTimerManager().SetTimer(SoundTH, this, &AC_TitlePlayerController::DelayTitleSound, 0.2f, false);
}

void AC_TitlePlayerController::InitSound()
{
	Super::InitSound();

	if (SoundManager)
	{
		SoundManager->PlayBGM(SoundManager->BGM_Title); // 원하는 BGM 지정
	}
}

void AC_TitlePlayerController::DelayTitleSound()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().ClearTimer(SoundTH);
}
