// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "WC_TitleWidget.generated.h"

/**
 * 
 */
class UButton;
class UComboBoxString;

UCLASS()
class OCCUPATION_API UWC_TitleWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnDifficultyModeChanged(FString Selected, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnTurnModeChanged(FString Selected, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnTribeChanged(FString Selected, ESelectInfo::Type SelectionType);

	void SetTitleWidgetIndex(int32 _CurSwitchNum);

	void SetDetailWidgetIndex(int32 _CurSwitchNum);

	void TitleInit();

	UFUNCTION()
	void OnTitleStartClicked();

	UFUNCTION()
	void OnTitleLoadClicked();

	UFUNCTION()
	void OnLevelChangeClicked();

	UFUNCTION()
	void OnGameSettingsClicked();

	UFUNCTION()
	void OnGameInfoClicked();

	UFUNCTION()
	void OnGameExitClicked();

	UFUNCTION()
	void OnTitleFirstBackClicked();

	UFUNCTION()
	void OnDisplayClicked();

	UFUNCTION()
	void OnVolumeClicked();

	UFUNCTION()
	void OnButtonHovered();

	void SaveEndFalse();

	void LoadButtonPossible();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	class USoundBase* HoverSound;

	//------------------------------------��ó�� Ÿ��Ʋ ȭ�� (0)
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* TitleWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
	UButton* LoadButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SettingButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GameInfoButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ExitButton;
	//---------------------------------------���� ���� �� ���� ȭ��(����, ���Ӹ�� ��) (1)
	UPROPERTY(meta = (BindWidget))
	UComboBoxString* Combo_DifficultyMode;

	UPROPERTY(meta = (BindWidget))
	UComboBoxString* Combo_TurnMode;

	UPROPERTY(meta = (BindWidget))
	UComboBoxString* Combo_Tribe;

	UPROPERTY(meta = (BindWidget))
	UButton* LevelChangeButton;

	UPROPERTY(meta = (BindWidget))
	UButton* TitleBackButton;
	//----------------------------------------���� ���� ȭ��(����, ���÷��� ��) (2)
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* DetailWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	UButton* DisplayButton;

	UPROPERTY(meta = (BindWidget))
	UButton* VolumeButton;

	UPROPERTY(meta = (BindWidget))
	UButton* TitleBackDetailButton;

	//----------------------------------------���� ���� (3)
	UPROPERTY(meta = (BindWidget))
	UButton* TitleBackInfoButton;
};
