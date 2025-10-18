// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "WC_InstructionWidget.generated.h"

/**
 * 
 */
class UButton;

UCLASS()
class OCCUPATION_API UWC_InstructionWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnInstructionCloseClicked();

	UFUNCTION()
	void OnGameRuleClicked();

	UFUNCTION()
	void OnGameDifficultyClicked();

	UFUNCTION()
	void OnGameTurnClicked();

	UFUNCTION()
	void OnGameTribeClicked();

	void SetInstructionWidgetIndex(int32 _CurSwitchNum);

	void InitGrayButtonColor();

	void BeginOpenSound();
public:
	void SetCloseButton();

private:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* InstructionSwitcher;

	UPROPERTY(meta = (BindWidget))
	UButton* CloseButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameRuleButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameDifficultyButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameTurnModeButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameTribeButton;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	class USoundBase* OpenSound;
};
