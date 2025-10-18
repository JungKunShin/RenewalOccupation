// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "Components/Slider.h"
#include "WC_VolumeWidget.generated.h"

/**
 * 
 */
class USlider;
class UTextBlock;

UCLASS()
class OCCUPATION_API UWC_VolumeWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnMasterVolumeChanged(float NewValue);

	UFUNCTION()
	void OnBGMVolumeChanged(float NewValue);

	UFUNCTION()
	void OnEffectVolumeChanged(float NewValue);

	UFUNCTION()
	void OnUIVolumeChanged(float NewValue);

private:
	void InitVolumeSound();

private:
	UPROPERTY(meta = (BindWidget))
	USlider* AudioVolumeSlider_Master;

	UPROPERTY(meta = (BindWidget))
	USlider* AudioVolumeSlider_BackGround;

	UPROPERTY(meta = (BindWidget))
	USlider* AudioVolumeSlider_Effect;

	UPROPERTY(meta = (BindWidget))
	USlider* AudioVolumeSlider_UI;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TEXT_Master;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TEXT_BGM;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TEXT_Effect;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TEXT_UI;

	FTimerHandle SoundInitTH;
};
