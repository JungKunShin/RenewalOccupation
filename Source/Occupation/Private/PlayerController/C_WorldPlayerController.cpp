// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/C_WorldPlayerController.h"
#include "HUD/C_WorldHUD.h"
#include "Manager/C_SoundManager.h"
#include "GameState/C_WorldGameState.h"

AC_WorldPlayerController::AC_WorldPlayerController()
{
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
}

void AC_WorldPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Map", IE_Pressed, this, &AC_WorldPlayerController::MapChecking);
	InputComponent->BindAction("Pause", IE_Pressed, this, &AC_WorldPlayerController::PauseOpen);
}

void AC_WorldPlayerController::MapChecking()
{
	AC_WorldHUD* WH = Cast< AC_WorldHUD>(GetHUD());
	if (!WH)return;

	if (IsMap)
	{
		WH->SetMapWidgetVisible(false);
	}
	else
	{
		WH->SetMapWidgetVisible(true);
	}
	IsMap = !IsMap;
}

void AC_WorldPlayerController::PauseOpen()
{
	AC_WorldHUD* WH = Cast< AC_WorldHUD>(GetHUD());
	if (!WH)return;

	if (IsPause)
	{
		WH->SetPauseWidgetVisible(false);
	}
	else
	{
		WH->SetPauseWidgetVisible(true);
	}
	IsPause = !IsPause;
}

void AC_WorldPlayerController::InitSound()
{
	Super::InitSound();



	if (SoundManager)
	{
		GetWorld()->GetTimerManager().ClearTimer(SoundTH);
		GetWorld()->GetTimerManager().SetTimer(SoundTH, this, &AC_WorldPlayerController::DelaySound, 1.f, false);
	}
}

void AC_WorldPlayerController::DelaySound()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (!WGS)return;

	if (WGS->Tribes[0] == EGameTribe::Korea)SoundManager->PlayBGM(SoundManager->BGM_Korea);
	else if (WGS->Tribes[0] == EGameTribe::China)SoundManager->PlayBGM(SoundManager->BGM_China);
	else if (WGS->Tribes[0] == EGameTribe::Egypt)SoundManager->PlayBGM(SoundManager->BGM_Egypt);

	GetWorld()->GetTimerManager().ClearTimer(SoundTH);
}
