// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/C_BaseGameMode.h"
#include "SaveGame/C_GameInfoSaveGame.h"
#include "C_WorldGameMode.generated.h"

/**
 * 
 */

UCLASS()
class OCCUPATION_API AC_WorldGameMode : public AC_BaseGameMode
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay()override;

	virtual void PostLogin(APlayerController* NewPlayer) override; //플레이어가 로그인시 호출되는 함수

public:
	void GameProcedure();

	void WhoInit();

	void TroopsInit();

	void OccupationColor();

	void LoadGameInfo();

	void GameInfoSave();
private:
	void TotalWarResult();

	void AIMoveTroops();

	void TurnJudgement();

	void BaseCampeJudgement();

	void SetAllPreTroops();

	void FindBaseStructure(FBaseStructureInfo _LoadInfo);

	void GameEndTrueSave();

private:
	int32 DeathAI = 0;
};
