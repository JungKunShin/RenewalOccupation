// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameState/C_BaseGameState.h"
#include "C_TitleGameState.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API AC_TitleGameState : public AC_BaseGameState
{
	GENERATED_BODY()
	
public:
	AC_TitleGameState();
public:
	EGameDifficulty CurGameDifficulty;

	EGameTurn CurGameTurn;

	TArray<EGameTribe>CurTribes;
};
