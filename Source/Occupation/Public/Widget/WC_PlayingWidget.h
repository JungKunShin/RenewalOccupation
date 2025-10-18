// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "WC_PlayingWidget.generated.h"

/**
 * 
 */
class UButton;
class UTextBlock;

UCLASS()
class OCCUPATION_API UWC_PlayingWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnTurnEndButtonClicked();

	UFUNCTION()
	void OnInstructionButtonClicked();

	void DelayEndTurn();

	void DelayInit();
private:
	UPROPERTY(meta = (BindWidget))
	UButton* TurnEndButton;

	UPROPERTY(meta = (BindWidget))
	class UBorder* TurnEndBorder;

	UPROPERTY(meta = (BindWidget))
	UButton* InstructionButton;

	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CurPlOccupation;

	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CurAI1Occupation;

	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CurAI2Occupation;

	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_TotalPlTroops;

	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_TotalAI1Troops;

	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_TotalAI2Troops;

	UPROPERTY(meta = (BindWiget))
	UTextBlock* Text_CurTurn;

	FTimerHandle TurnEndTH;

	FTimerHandle TextTH;
};
