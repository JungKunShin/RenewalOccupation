// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/C_TitleGameMode.h"
#include "GameState/C_TitleGameState.h"

void AC_TitleGameMode::AITribeChoice()
{
	OneTribeChoice();
	TwoTribeChoice();
}

void AC_TitleGameMode::OneTribeChoice()
{
	AC_TitleGameState* TGS = GetWorld()->GetGameState< AC_TitleGameState>();
	if (!TGS)return;

	int32 RandomInt = FMath::RandRange(0, 2);
	EGameTribe CurTribe = EGameTribe::Korea;

	switch (RandomInt)
	{
	case 0:
		CurTribe = EGameTribe::Korea;
		break;
	case 1:
		CurTribe = EGameTribe::China;
		break;
	case 2:
		CurTribe = EGameTribe::Egypt;
		break;
	default:
		break;
	}
	if (TGS->CurTribes[0] != CurTribe)
	{
		TGS->CurTribes[1] = CurTribe;
	}
	else
	{
		OneTribeChoice();
	}

}

void AC_TitleGameMode::TwoTribeChoice()
{
	AC_TitleGameState* TGS = GetWorld()->GetGameState< AC_TitleGameState>();
	if (!TGS)return;

	int32 RandomInt = FMath::RandRange(0, 2);
	EGameTribe CurTribe = EGameTribe::Korea;

	switch (RandomInt)
	{
	case 0:
		CurTribe = EGameTribe::Korea;
		break;
	case 1:
		CurTribe = EGameTribe::China;
		break;
	case 2:
		CurTribe = EGameTribe::Egypt;
		break;
	default:
		break;
	}
	if (TGS->CurTribes[0] != CurTribe && TGS->CurTribes[1]!=CurTribe)
	{
		TGS->CurTribes[2] = CurTribe;
	}
	else
	{
		TwoTribeChoice();
	}
}
