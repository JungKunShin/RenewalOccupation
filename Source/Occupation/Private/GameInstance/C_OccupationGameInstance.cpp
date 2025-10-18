// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/C_OccupationGameInstance.h"
#include "SaveGame/C_GameInfoSaveGame.h"
#include "Kismet/GameplayStatics.h"

UC_OccupationGameInstance::UC_OccupationGameInstance(const FObjectInitializer& ObjectInitializer)
{
	CurGameDifficulty = EGameDifficulty::Easy;
	CurGameTurn = EGameTurn::Twenty;
	CurGameTribes.Init(EGameTribe::Korea, 3);
	CurGameTribes[0] = EGameTribe::Korea;
	CurGameTribes[1] = EGameTribe::China;
	CurGameTribes[2] = EGameTribe::Egypt;
}

void UC_OccupationGameInstance::Init()
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("GameInfoSlot"), 0))
	{
		UC_GameInfoSaveGame* LoadGameInstance = Cast<UC_GameInfoSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("GameInfoSlot"), 0));

		IsEnd = LoadGameInstance->IsEnd;
	}
}

void UC_OccupationGameInstance::SetNewGameInfo(EGameDifficulty _CurGameDifficulty, EGameTurn _CurGameTurn,TArray<EGameTribe>_CurGameTribes)
{
	CurGameDifficulty = _CurGameDifficulty;
	CurGameTurn = _CurGameTurn;
	CurGameTribes = _CurGameTribes;
}
