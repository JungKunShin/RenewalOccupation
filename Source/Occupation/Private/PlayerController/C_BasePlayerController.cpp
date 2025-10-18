// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/C_BasePlayerController.h"
#include "Manager/C_SoundManager.h"
#include "SaveGame/C_SoundSaveGame.h"
#include "Kismet/GameplayStatics.h"

void AC_BasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitSound();

	LoadSoundSettings();
}

void AC_BasePlayerController::InitSound()
{
	SoundManager = GetWorld()->SpawnActor<AC_SoundManager>(SoundManagerClass);

	if (SoundManager)
	{
		SoundManager->InitSoundManager();
	}
}

void AC_BasePlayerController::SaveSoundSettings()
{
	UC_SoundSaveGame* SaveGameInstance = Cast<UC_SoundSaveGame>(UGameplayStatics::CreateSaveGameObject(UC_SoundSaveGame::StaticClass()));

	SaveGameInstance->MasterVolume = SoundManager->MasterVolume;
	SaveGameInstance->BGMVolume = SoundManager->BGMVolume;
	SaveGameInstance->EffectVolume = SoundManager->EffectVolume;
	SaveGameInstance->OriginalUIVolume = SoundManager->OriginalUIVolume;

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SoundSlot"), 0);
}

void AC_BasePlayerController::LoadSoundSettings()
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("SoundSlot"), 0))
	{
		UC_SoundSaveGame* LoadGameInstance = Cast<UC_SoundSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SoundSlot"), 0));

		SoundManager->MasterVolume = LoadGameInstance->MasterVolume;
		SoundManager->BGMVolume = LoadGameInstance->BGMVolume;
		SoundManager->EffectVolume = LoadGameInstance->EffectVolume;
		SoundManager->OriginalUIVolume = LoadGameInstance->OriginalUIVolume;

		SoundManager->InitSoundManager();
	}
}

AC_SoundManager* AC_BasePlayerController::GetSoundManager()
{
	if (SoundManager) {
		return SoundManager;
	}
	else {
		InitSound();
		/*LoadSoundSettings();*/
		return SoundManager;
	}
}
