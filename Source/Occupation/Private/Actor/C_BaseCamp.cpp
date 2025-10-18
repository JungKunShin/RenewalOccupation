// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_BaseCamp.h"

void AC_BaseCamp::BeginPlay()
{
	Super::BeginPlay();

	if (this->Tags[0] == FName("BCR"))
	{
		TroopInfo.PlayerTroops = 50;
		TroopInfo.Who = EWho::Player;
	}
	else if (this->Tags[0] == FName("BCB"))
	{
		TroopInfo.AI1Troops = 50;
		TroopInfo.Who = EWho::AIOne;
	}
	else if (this->Tags[0] == FName("BCG"))
	{
		TroopInfo.AI2Troops = 50;
		TroopInfo.Who = EWho::AITwo;
	}
}
