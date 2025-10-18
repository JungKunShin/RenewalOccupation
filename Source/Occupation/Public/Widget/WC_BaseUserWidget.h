// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WC_BaseUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API UWC_BaseUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

protected:
	void WidgetBeginSoundInit();

	void WidgetButtonSoundInit();

	void BackButtonSoundInit();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* BeginSound;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* ButtonSound;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* BackButtonSound;
};
