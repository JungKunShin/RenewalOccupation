// Fill out your copyright notice in the Description page of Project Settings.


#include "GameState/C_TitleGameState.h"

AC_TitleGameState::AC_TitleGameState()
{
	CurGameDifficulty = EGameDifficulty::Easy;
	CurGameTurn = EGameTurn::Twenty;
	CurTribes.Init(EGameTribe::Korea, 3);

	CurTribes[0] = EGameTribe::Korea;
	CurTribes[1] = EGameTribe::China;
	CurTribes[2] = EGameTribe::Egypt;
}
