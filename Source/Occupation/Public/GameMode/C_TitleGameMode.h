// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameMode/C_BaseGameMode.h"
#include "C_TitleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API AC_TitleGameMode : public AC_BaseGameMode
{
	GENERATED_BODY()
	
public:
	void AITribeChoice();

private:
	void OneTribeChoice();

	void TwoTribeChoice();
};
