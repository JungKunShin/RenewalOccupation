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
	bool IsLoad = false; //게임이 로드 됐는가? 로드 된 파일이면 로드 된 정보들을 가져오고, 아니면 처음부터

	bool IsEnd = false; //게임이 끝났는가? 그러면 다시 로드 못하도록

	EGameDifficulty CurGameDifficulty;

	EGameTurn CurGameTurn;

	TArray<EGameTribe>CurGameTribes;
};
