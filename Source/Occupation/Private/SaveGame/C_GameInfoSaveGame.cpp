// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGame/C_GameInfoSaveGame.h"

UC_GameInfoSaveGame::UC_GameInfoSaveGame()
{
	TestInfo.TagName = "BCR";
	TestInfo.PlayerTroops = 10;
	TestInfo.AI1Troops = 0;
	TestInfo.AI2Troops = 0;
	TestInfo.PrePlTroops = 0;
	TestInfo.PreAI1Troops = 0;
	TestInfo.PreAI2Troops = 0;
	TestInfo.Who = EWho::None;

	IsEnd = false;
	SaveTroopInfo.Init(TestInfo, 19);
	CurTurn = 1;
	CurDifficulty = EGameDifficulty::Easy;
	CurGameTurnMode = EGameTurn::Twenty;
	CurTribes.Init(EGameTribe::Korea, 3);
	IsAIOneLose = false;
	IsAITwoLose = false;
}
