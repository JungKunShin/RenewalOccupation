// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "WC_PauseWidget.generated.h"

/**
 * 
 */
class UButton;

UCLASS()
class OCCUPATION_API UWC_PauseWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnResumeClicked();

	UFUNCTION()
	void OnPauseSaveClicked();

	UFUNCTION()
	void OnSettingClicked();

	UFUNCTION()
	void OnPauseTitleBackClicked();

	UFUNCTION()
	void OnExitClicked();

	UFUNCTION()
	void OnWorldDisplayClicked();

	UFUNCTION()
	void OnWorldVolumeClicked();

	UFUNCTION()
	void OnPauseBackClicked();

	void SetPauseWidgetIndex(int32 _CurSwitchNum);

	void SetSettingsWidgetIndex(int32 _CurSwitchNum);

private:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* PauseTotalWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* PauseSettingWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	UButton* ResumeButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SaveButton;
	
	UPROPERTY(meta = (BindWidget))
	UButton* SettingButton;

	UPROPERTY(meta = (BindWidget))
	UButton* PauseTitleBackButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ExitButton;

	UPROPERTY(meta = (BindWidget))
	UButton* DisplayButton;

	UPROPERTY(meta = (BindWidget))
	UButton* VolumeButton;

	UPROPERTY(meta = (BindWidget))
	UButton* PauseBackButton;
};
