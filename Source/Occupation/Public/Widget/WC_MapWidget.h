// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "Actor/C_BaseStructure.h"
#include "WC_MapWidget.generated.h"

/**
 * 
 */
class UTextBlock;
class UImage;

UCLASS()
class OCCUPATION_API UWC_MapWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	void InitColor(UImage* _Image,EWho _Who);
	void InitText(UTextBlock* _TextBlock, EWho _Who,FName _TagName, UTextBlock* _CanTextBlock);
	EWho WhoOwn(FName _TagName);

	void BCRInit();
	void BCBInit();
	void BCGInit();
	void T1AInit();
	void T1BInit();
	void T1CInit();
	void T2AInit();
	void T2BInit();
	void T2CInit();
	void T3AInit();
	void T3BInit();
	void T3CInit();
	void T4AInit();
	void T4BInit();
	void T4CInit();
	void T5AInit();
	void T5BInit();
	void T5CInit();
	void CenterInit();

public:
	UPROPERTY(meta = (BindWiget))
	UImage* BCRColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_BCRTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanBCRTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* BCBColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_BCBTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanBCBTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* BCGColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_BCGTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanBCGTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T1AColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T1ATroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT1ATroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T1BColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T1BTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT1BTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T1CColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T1CTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT1CTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T2AColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T2ATroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT2ATroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T2BColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T2BTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT2BTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T2CColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T2CTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT2CTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T3AColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T3ATroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT3ATroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T3BColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T3BTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT3BTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T3CColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T3CTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT3CTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T4AColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T4ATroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT4ATroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T4BColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T4BTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT4BTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T4CColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T4CTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT4CTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T5AColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T5ATroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT5ATroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T5BColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T5BTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT5BTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* T5CColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_T5CTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanT5CTroop;

	UPROPERTY(meta = (BindWiget))
	UImage* CenterColor;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CenterTroop;
	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CanCenterTroop;
};
