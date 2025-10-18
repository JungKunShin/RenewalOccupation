// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "C_SoundSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API UC_SoundSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

    UC_SoundSaveGame();

    UPROPERTY(VisibleAnywhere, Category = "Sound")
    float MasterVolume;

    UPROPERTY(VisibleAnywhere, Category = "Sound")
    float BGMVolume;

    UPROPERTY(VisibleAnywhere, Category = "Sound")
    float EffectVolume;

    UPROPERTY(VisibleAnywhere, Category = "Sound")
    float OriginalUIVolume;
};
