// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "GameState/C_BaseGameState.h"
#include "WC_ResultWidget.generated.h"

/**
 * 
 */
class UFileMediaSource;
class UTextBlock;

UCLASS()
class OCCUPATION_API UWC_ResultWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	void WinResult(int32 _Result);

	void SetResultWidgetIndex(int32 _CurSwitchNum);

	UFUNCTION()
	void ResultVideoEnd();

	UFUNCTION()
	void OnTitleBackClicked();

	void InitTextBlock();

	void PlayerLose();

	void AllOccupyWin();

	void TribeDistinguish(EGameTribe _Tribe,UTextBlock* _TextBlock);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Video")
	class UMediaPlayer* MediaPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Video")
	UFileMediaSource* WinSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Video")
	UFileMediaSource* LoseSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Video")
	UFileMediaSource* DrawSource;

private:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* ResultWidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_Win;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_Lose;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_Draw;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_MyOccupation;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AIOneOccupation;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AITwoOccupation;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_MyTotalTroops;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AIOneTotalTroops;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AITwoTotalTroops;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_PlCollapse;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AIOneCollapse;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AITwoCollapse;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_TakedTurn;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_WinGameCondition;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_GameDifficulty;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_GameTurnMode;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_TurnEnd;

	UPROPERTY(meta = (BindWidget))
	class UButton* TitleBackButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_PlayerTribe;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AIOneTribe;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_AITwoTribe;
};
