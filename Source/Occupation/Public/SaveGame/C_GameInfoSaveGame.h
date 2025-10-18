// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameState/C_BaseGameState.h"
#include "Actor/C_BaseStructure.h"
#include "C_GameInfoSaveGame.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FBaseStructureInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY() 
	FName TagName=FName("BCR");

	UPROPERTY() 
	int32 PlayerTroops=0;
	
	UPROPERTY()
	int32 AI1Troops=0;

	UPROPERTY()
	int32 AI2Troops = 0;

	UPROPERTY()
	int32 PrePlTroops = 0;

	UPROPERTY()
	int32 PreAI1Troops = 0;

	UPROPERTY()
	int32 PreAI2Troops = 0;

	UPROPERTY()
	EWho Who = EWho::None;
};

UCLASS()
class OCCUPATION_API UC_GameInfoSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UC_GameInfoSaveGame();

public:
	UPROPERTY()
	bool IsEnd;

	UPROPERTY()
	TArray<FBaseStructureInfo>SaveTroopInfo;

	UPROPERTY()
	int32 CurTurn;

	UPROPERTY()
	EGameDifficulty CurDifficulty;

	UPROPERTY()
	EGameTurn CurGameTurnMode;

	UPROPERTY()
	TArray<EGameTribe>CurTribes;

	UPROPERTY()
	bool IsAIOneLose;
	UPROPERTY()
	bool IsAITwoLose;

private:
	UPROPERTY()
	FBaseStructureInfo TestInfo;
};
