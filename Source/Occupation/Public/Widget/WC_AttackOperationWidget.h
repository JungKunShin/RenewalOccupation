// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "WC_AttackOperationWidget.generated.h"

/**
 * 
 */
class UButton;

UCLASS()
class OCCUPATION_API UWC_AttackOperationWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnBCRButtonClicked(); // 레드 본진 버튼

	UFUNCTION()
	void OnBCBButtonClicked(); // 블루 본진 버튼

	UFUNCTION()
	void OnBCGButtonClicked(); // 그린 본진 버튼

	UFUNCTION()
	void OnT1AButtonClicked(); // T1A 버튼

	UFUNCTION()
	void OnT1BButtonClicked(); // T1B 버튼

	UFUNCTION()
	void OnT1CButtonClicked(); // T1C 버튼

	UFUNCTION()
	void OnT2AButtonClicked(); // T2A 버튼

	UFUNCTION()
	void OnT2BButtonClicked(); // T2B 버튼

	UFUNCTION()
	void OnT2CButtonClicked(); // T2C 버튼

	UFUNCTION()
	void OnT3AButtonClicked(); // T3A 버튼

	UFUNCTION()
	void OnT3BButtonClicked(); // T3B 버튼

	UFUNCTION()
	void OnT3CButtonClicked(); // T3C 버튼

	UFUNCTION()
	void OnT4AButtonClicked(); // T4A 버튼

	UFUNCTION()
	void OnT4BButtonClicked(); // T4B 버튼

	UFUNCTION()
	void OnT4CButtonClicked(); // T4C 버튼

	UFUNCTION()
	void OnT5AButtonClicked(); // T5A 버튼

	UFUNCTION()
	void OnT5BButtonClicked(); // T5B 버튼

	UFUNCTION()
	void OnT5CButtonClicked(); // T5C 버튼

	UFUNCTION()
	void OnCenterButtonClicked(); // 센터 버튼

	UFUNCTION()
	void OnWidgetBackButtonClicked(); // 뒤로 버튼

	UFUNCTION()
	void OnMoveButtonClicked(); // 이동 버튼

	UFUNCTION()
	void OnTroopUpButtonClicked(); // 병사증가 버튼

	UFUNCTION()
	void OnTroopTenUpButtonClicked(); // 병사증가 버튼

	UFUNCTION()
	void OnTroopDownButtonClicked(); // 병사감소 버튼

	UFUNCTION()
	void OnTroopTenDownButtonClicked(); // 병사감소 버튼

	void InitButtonColor(); // 처음 버튼 소유권 색깔

	void CloselyJudgement();
private:
	UPROPERTY(meta = (BindWidget))
	UButton* BCRButton;			// 레드 본진

	UPROPERTY(meta = (BindWidget))
	UButton* BCBButton;			// 블루 본진

	UPROPERTY(meta = (BindWidget))
	UButton* BCGButton;			// 그린 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T1AButton;			// T1A 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T1BButton;			// T1B 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T1CButton;			// T1C 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T2AButton;			// T2A 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T2BButton;			// T2B 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T2CButton;			// T2C 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T3AButton;			// T3A 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T3BButton;			// T3B 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T3CButton;			// T3C 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T4AButton;			// T4A 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T4BButton;			// T4B 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T4CButton;			// T4C 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T5AButton;			// T5A 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T5BButton;			// T5B 본진

	UPROPERTY(meta = (BindWidget))
	UButton* T5CButton;			// T5C 본진

	UPROPERTY(meta = (BindWidget))
	UButton* CenterButton;			// T5C 본진

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* AttackWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	UButton* FirstBackButton;		

	UPROPERTY(meta = (BindWidget))
	UButton* SecondBackButton;

	UPROPERTY(meta = (BindWidget))
	UButton* TroopUpButton;

	UPROPERTY(meta = (BindWidget))
	UButton* TroopDownButton;

	UPROPERTY(meta = (BindWidget))
	UButton* TroopTenUpButton;

	UPROPERTY(meta = (BindWidget))
	UButton* TroopTenDownButton;

	UPROPERTY(meta = (BindWidget))
	UButton* MoveButton;

	UPROPERTY(meta = (BindWidget))
	class UBorder* MoveButtonBorder;

	UPROPERTY(meta = (BindWiget))
	class UTextBlock* Text_CanTroops;

	UPROPERTY(meta = (BindWiget))
	class UTextBlock* Text_CurTroops;

	int32 CurTroops = 0;

	FName TagName;
};
