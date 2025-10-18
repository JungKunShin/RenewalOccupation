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
	void OnBCRButtonClicked(); // ���� ���� ��ư

	UFUNCTION()
	void OnBCBButtonClicked(); // ��� ���� ��ư

	UFUNCTION()
	void OnBCGButtonClicked(); // �׸� ���� ��ư

	UFUNCTION()
	void OnT1AButtonClicked(); // T1A ��ư

	UFUNCTION()
	void OnT1BButtonClicked(); // T1B ��ư

	UFUNCTION()
	void OnT1CButtonClicked(); // T1C ��ư

	UFUNCTION()
	void OnT2AButtonClicked(); // T2A ��ư

	UFUNCTION()
	void OnT2BButtonClicked(); // T2B ��ư

	UFUNCTION()
	void OnT2CButtonClicked(); // T2C ��ư

	UFUNCTION()
	void OnT3AButtonClicked(); // T3A ��ư

	UFUNCTION()
	void OnT3BButtonClicked(); // T3B ��ư

	UFUNCTION()
	void OnT3CButtonClicked(); // T3C ��ư

	UFUNCTION()
	void OnT4AButtonClicked(); // T4A ��ư

	UFUNCTION()
	void OnT4BButtonClicked(); // T4B ��ư

	UFUNCTION()
	void OnT4CButtonClicked(); // T4C ��ư

	UFUNCTION()
	void OnT5AButtonClicked(); // T5A ��ư

	UFUNCTION()
	void OnT5BButtonClicked(); // T5B ��ư

	UFUNCTION()
	void OnT5CButtonClicked(); // T5C ��ư

	UFUNCTION()
	void OnCenterButtonClicked(); // ���� ��ư

	UFUNCTION()
	void OnWidgetBackButtonClicked(); // �ڷ� ��ư

	UFUNCTION()
	void OnMoveButtonClicked(); // �̵� ��ư

	UFUNCTION()
	void OnTroopUpButtonClicked(); // �������� ��ư

	UFUNCTION()
	void OnTroopTenUpButtonClicked(); // �������� ��ư

	UFUNCTION()
	void OnTroopDownButtonClicked(); // ���簨�� ��ư

	UFUNCTION()
	void OnTroopTenDownButtonClicked(); // ���簨�� ��ư

	void InitButtonColor(); // ó�� ��ư ������ ����

	void CloselyJudgement();
private:
	UPROPERTY(meta = (BindWidget))
	UButton* BCRButton;			// ���� ����

	UPROPERTY(meta = (BindWidget))
	UButton* BCBButton;			// ��� ����

	UPROPERTY(meta = (BindWidget))
	UButton* BCGButton;			// �׸� ����

	UPROPERTY(meta = (BindWidget))
	UButton* T1AButton;			// T1A ����

	UPROPERTY(meta = (BindWidget))
	UButton* T1BButton;			// T1B ����

	UPROPERTY(meta = (BindWidget))
	UButton* T1CButton;			// T1C ����

	UPROPERTY(meta = (BindWidget))
	UButton* T2AButton;			// T2A ����

	UPROPERTY(meta = (BindWidget))
	UButton* T2BButton;			// T2B ����

	UPROPERTY(meta = (BindWidget))
	UButton* T2CButton;			// T2C ����

	UPROPERTY(meta = (BindWidget))
	UButton* T3AButton;			// T3A ����

	UPROPERTY(meta = (BindWidget))
	UButton* T3BButton;			// T3B ����

	UPROPERTY(meta = (BindWidget))
	UButton* T3CButton;			// T3C ����

	UPROPERTY(meta = (BindWidget))
	UButton* T4AButton;			// T4A ����

	UPROPERTY(meta = (BindWidget))
	UButton* T4BButton;			// T4B ����

	UPROPERTY(meta = (BindWidget))
	UButton* T4CButton;			// T4C ����

	UPROPERTY(meta = (BindWidget))
	UButton* T5AButton;			// T5A ����

	UPROPERTY(meta = (BindWidget))
	UButton* T5BButton;			// T5B ����

	UPROPERTY(meta = (BindWidget))
	UButton* T5CButton;			// T5C ����

	UPROPERTY(meta = (BindWidget))
	UButton* CenterButton;			// T5C ����

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
