// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "C_BaseGameState.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGameDifficulty : uint8
{
	Easy,
	Normal,
	Hard
};

UENUM(BlueprintType)
enum class EGameTurn : uint8
{
	Twenty,
	Thirty,
	Forty,
	Infinite
};

UENUM(BlueprintType)
enum class EGameTribe : uint8
{
	Korea,
	China,
	Egypt
};


UCLASS()
class OCCUPATION_API AC_BaseGameState : public AGameState
{
	GENERATED_BODY()
	
};
