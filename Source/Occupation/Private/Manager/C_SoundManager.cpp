// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/C_SoundManager.h"

// Sets default values
AC_SoundManager::AC_SoundManager()
{
    BGMComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("BGMComponent"));

    BGMComponent->bIsUISound = true;
    BGMComponent->bAutoDestroy = false;
}

// Called when the game starts or when spawned
void AC_SoundManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_SoundManager::InitSoundManager()
{
    SetAllMasterVolume(MasterVolume);
}

void AC_SoundManager::PlayBGM(USoundBase* BGM)
{
    if (BGMComponent && BGM)
    {
        BGMComponent->SetSound(BGM);
        BGMComponent->Play();
        CurBGM = BGM;
    }
}

void AC_SoundManager::StopBGM()
{
    if (BGMComponent)
    {
        BGMComponent->Stop();
    }
}

void AC_SoundManager::SetAllMasterVolume(float Volume)
{
    MasterVolume = Volume;
    SetBGMVolume(BGMVolume);
    SetEffectVolume(EffectVolume);
    SetUIVolume(OriginalUIVolume);
}

void AC_SoundManager::SetBGMVolume(float Volume)
{
    if (BGMComponent)
    {
        BGMVolume = Volume;
        float ResultVolume = (MasterVolume * BGMVolume);
        BGMComponent->SetVolumeMultiplier(FMath::Clamp(ResultVolume, 0.001f, 1.0f));
    }
}

void AC_SoundManager::SetEffectVolume(float Volume)
{
    EffectVolume = Volume;
    for (auto Comp : ActiveEffectComponents)
    {
        float ResultVolume = (MasterVolume * EffectVolume);
        Comp->SetVolumeMultiplier(FMath::Clamp(ResultVolume, 0.001f, 1.0f));
    }
}

void AC_SoundManager::SetUIVolume(float Volume)
{
    OriginalUIVolume = Volume;
    UIVolume = OriginalUIVolume * MasterVolume;
}

