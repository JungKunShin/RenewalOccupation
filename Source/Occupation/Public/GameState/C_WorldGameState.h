// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameState/C_BaseGameState.h"
#include "C_WorldGameState.generated.h"

/**
 * 
 */
class AC_BaseStructure;

UCLASS()
class OCCUPATION_API AC_WorldGameState : public AC_BaseGameState
{
	GENERATED_BODY()
	
public:
	AC_WorldGameState();

protected:
	virtual void BeginPlay()override;

public:
	void SetStructure(AC_BaseStructure* _CurStructure);

	AC_BaseStructure* GetStructure();

	void IncreaseTurn();

	int32 GetTurn();

	int32 GetEndTurn();

	void SetEndTurn();

private:
	AC_BaseStructure* CurAttackStructure = nullptr;

	int32 EndTurn;
public:
	TArray<int32> Occupation;

	TArray<int32> TotalTroops;

	TArray<EGameTribe>Tribes;

	EGameDifficulty CurDifficulty;

	EGameTurn CurGameTurnMode;

	int32 Turn;

	bool IsAIOneLose = false;
	bool IsAITwoLose = false;
};
