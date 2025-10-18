// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C_BasePlayerController.generated.h"

/**
 * 
 */
class AC_SoundManager;

UCLASS()
class OCCUPATION_API AC_BasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay()override;

	virtual void InitSound();

public:
	void SaveSoundSettings();

	void LoadSoundSettings();

	UFUNCTION(BlueprintCallable)
	AC_SoundManager* GetSoundManager();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager")
	TSubclassOf<AC_SoundManager> SoundManagerClass;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager")
	AC_SoundManager* SoundManager;
};
