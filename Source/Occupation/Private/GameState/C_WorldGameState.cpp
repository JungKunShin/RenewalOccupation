// Fill out your copyright notice in the Description page of Project Settings.


#include "GameState/C_WorldGameState.h"
#include "GameInstance/C_OccupationGameInstance.h"
#include "GameMode/C_WorldGameMode.h"

#include "Actor/C_BaseStructure.h"
#include "Kismet/GameplayStatics.h"

AC_WorldGameState::AC_WorldGameState()
{
    Occupation.Init(0, 3);
    TotalTroops.Init(0, 3);
    Tribes.Init(EGameTribe::Korea, 3);
    Tribes[0] = EGameTribe::Korea;
    Tribes[1] = EGameTribe::China;
    Tribes[2] = EGameTribe::Egypt;
    Turn = 1;
}

void AC_WorldGameState::BeginPlay()
{
    Super::BeginPlay();

    UC_OccupationGameInstance* OccupationGameInstance = GetGameInstance<UC_OccupationGameInstance>();
    AC_WorldGameMode* WGM = Cast<AC_WorldGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    if (!WGM)return;

    if (OccupationGameInstance->IsLoad)
    {
        WGM->LoadGameInfo();
        SetEndTurn();
        WGM->OccupationColor();
    }
    else
    {
        Tribes = OccupationGameInstance->CurGameTribes;
        CurDifficulty = OccupationGameInstance->CurGameDifficulty;
        CurGameTurnMode = OccupationGameInstance->CurGameTurn;
        SetEndTurn();
        WGM->OccupationColor();
    }

}

void AC_WorldGameState::SetStructure(AC_BaseStructure* _CurStructure)
{
    CurAttackStructure = _CurStructure;
}

AC_BaseStructure* AC_WorldGameState::GetStructure()
{
    return CurAttackStructure;
}

void AC_WorldGameState::IncreaseTurn()
{
    ++Turn;
}

int32 AC_WorldGameState::GetTurn()
{
    return Turn;
}

int32 AC_WorldGameState::GetEndTurn()
{
    return EndTurn;
}

void AC_WorldGameState::SetEndTurn()
{
    switch (CurGameTurnMode)
    {
    case EGameTurn::Twenty:
        EndTurn = 20;
        break;
    case EGameTurn::Thirty:
        EndTurn = 30;
        break;
    case EGameTurn::Forty:
        EndTurn = 40;
        break;
    case EGameTurn::Infinite:
        EndTurn = 999;
        break;
    }
}