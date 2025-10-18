// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameInstance/C_BaseGameInstance.h"
#include "GameState/C_BaseGameState.h"
#include "C_OccupationGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API UC_OccupationGameInstance : public UC_BaseGameInstance
{
	GENERATED_BODY()
	
public:
	UC_OccupationGameInstance(const FObjectInitializer& ObjectInitializer);
private:
	virtual void Init()override;

public:
	void SetNewGameInfo(EGameDifficulty _CurGameDifficulty, EGameTurn _CurGameTurn, TArray<EGameTribe>_CurGameTribes);

public:
	bool IsLoad = false; //������ �ε� �ƴ°�? �ε� �� �����̸� �ε� �� �������� ��������, �ƴϸ� ó������

	bool IsEnd = false; //������ �����°�? �׷��� �ٽ� �ε� ���ϵ���

	EGameDifficulty CurGameDifficulty;

	EGameTurn CurGameTurn;

	TArray<EGameTribe>CurGameTribes;
};
