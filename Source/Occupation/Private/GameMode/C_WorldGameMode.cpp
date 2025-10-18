// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/C_WorldGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Actor/C_BaseStructure.h"
#include "GameState/C_WorldGameState.h"
#include "PlayerController/C_WorldPlayerController.h"
#include "HUD/C_WorldHUD.h"

#include "SaveGame/C_GameInfoSaveGame.h"
#include "GameInstance/C_OccupationGameInstance.h"

void AC_WorldGameMode::BeginPlay()
{
}

void AC_WorldGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AC_WorldGameMode::GameProcedure()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (!WGS)return;

	WGS->IncreaseTurn();
	AIMoveTroops();
	TotalWarResult();
	TurnJudgement();
	if (WGS->GetTurn() <= WGS->GetEndTurn())
	{
		BaseCampeJudgement();
	}
	WhoInit();
	TroopsInit();
	SetAllPreTroops();
	/*TestSave();*/
}

void AC_WorldGameMode::WhoInit()
{
	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), StructureActor);
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	WGS->Occupation[0] = 0;
	WGS->Occupation[1] = 0;
	WGS->Occupation[2] = 0;

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			switch (CurStructure->TroopInfo.Who)
			{
			case EWho::Player:
				++WGS->Occupation[0];
				break;
			case EWho::AIOne:
				++WGS->Occupation[1];
				break;
			case EWho::AITwo:
				++WGS->Occupation[2];
				break;
			case EWho::None:
			default:
				break;
			}
		}
	}
}

void AC_WorldGameMode::TroopsInit()
{
	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), StructureActor);
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	WGS->TotalTroops[0] = 0;
	WGS->TotalTroops[1] = 0;
	WGS->TotalTroops[2] = 0;

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			WGS->TotalTroops[0] += CurStructure->TroopInfo.PlayerTroops;
			WGS->TotalTroops[1] += CurStructure->TroopInfo.AI1Troops;
			WGS->TotalTroops[2] += CurStructure->TroopInfo.AI2Troops;
		}
	}
}

void AC_WorldGameMode::TotalWarResult()
{
	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), StructureActor);

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			CurStructure->PlayersWar();
		}
	}
}

void AC_WorldGameMode::AIMoveTroops()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), StructureActor);

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			if (!WGS->IsAIOneLose)
			{
				CurStructure->AIOneMove();
			}

			if (!WGS->IsAITwoLose)
			{
				CurStructure->AITwoMove();
			}
		}
	}
}

void AC_WorldGameMode::TurnJudgement()
{
	AC_WorldPlayerController* WPC = Cast< AC_WorldPlayerController>(GetWorld()->GetFirstPlayerController());
	AC_WorldHUD* WH = Cast< AC_WorldHUD>(WPC->GetHUD());

	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (WGS)
	{
		if (WGS->GetTurn() > WGS->GetEndTurn())
		{
			GameEndTrueSave();
			if (WGS->Occupation[0] > WGS->Occupation[1] && WGS->Occupation[0] > WGS->Occupation[2])//이겼을때
			{
				WH->SetResultWidgetVisible(true,1);
			}
			else if (WGS->Occupation[1] > WGS->Occupation[0] || WGS->Occupation[2] > WGS->Occupation[0])//졌을때
			{
				WH->SetResultWidgetVisible(true,2);
			}
			else//비겼을때
			{
				WH->SetResultWidgetVisible(true,3);
			}
			
		}
	}
}

void AC_WorldGameMode::BaseCampeJudgement()
{
	DeathAI = 0;

	AC_WorldPlayerController* WPC = Cast< AC_WorldPlayerController>(GetWorld()->GetFirstPlayerController());
	AC_WorldHUD* WH = Cast< AC_WorldHUD>(WPC->GetHUD());
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	TArray<AActor*> PlayerActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "BCR", PlayerActor);
	TArray<AActor*> AIOneActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "BCB", AIOneActor);
	TArray<AActor*> AITwoActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "BCG", AITwoActor);

	for (AActor* MyActor : PlayerActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			if (CurStructure->TroopInfo.Who != EWho::Player)
			{
				TArray<AActor*> PlayerExtinctActor;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), PlayerExtinctActor);
				for (AActor* MyExtinctActor : PlayerExtinctActor)
				{
					AC_BaseStructure* CurExtinctStructure = Cast<AC_BaseStructure>(MyExtinctActor);

					if (CurExtinctStructure)
					{
						CurExtinctStructure->TroopInfo.PlayerTroops = 0;
						if (CurExtinctStructure->TroopInfo.Who == EWho::Player)
						{
							CurExtinctStructure->TroopInfo.Who = EWho::None;
						}
					}
				}
				GameEndTrueSave();
				WhoInit();
				TroopsInit();


				WH->SetResultWidgetVisible(true, 2);
				WH->SetResultWidgetPlayerLose();
				WH->SetResultWidgetAllOccupy();
				return;
			}
		}
	}
	for (AActor* MyActor : AIOneActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			if (CurStructure->TroopInfo.Who != EWho::AIOne)
			{
				++DeathAI;
				if (!WGS->IsAIOneLose)
				{
					WGS->IsAIOneLose = true;
					TArray<AActor*> AIOneExtinctActor;
					UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), AIOneExtinctActor);
					for (AActor* MyExtinctActor : AIOneExtinctActor)
					{
						AC_BaseStructure* CurExtinctStructure = Cast<AC_BaseStructure>(MyExtinctActor);

						if (CurExtinctStructure)
						{
							CurExtinctStructure->TroopInfo.AI1Troops = 0;
							if (CurExtinctStructure->TroopInfo.Who == EWho::AIOne)
							{
								CurExtinctStructure->TroopInfo.Who = EWho::None;
								CurExtinctStructure->SurrenderAI();
							}
						}
					}
				}
				break;
			}
		}
	}
	for (AActor* MyActor : AITwoActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			if (CurStructure->TroopInfo.Who != EWho::AITwo)
			{
				++DeathAI;
				if (!WGS->IsAITwoLose)
				{
					WGS->IsAITwoLose = true;
					TArray<AActor*> AITwoExtinctActor;
					UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), AITwoExtinctActor);
					for (AActor* MyExtinctActor : AITwoExtinctActor)
					{
						AC_BaseStructure* CurExtinctStructure = Cast<AC_BaseStructure>(MyExtinctActor);

						if (CurExtinctStructure)
						{
							CurExtinctStructure->TroopInfo.AI2Troops = 0;
							if (CurExtinctStructure->TroopInfo.Who == EWho::AITwo)
							{
								CurExtinctStructure->TroopInfo.Who = EWho::None;
								CurExtinctStructure->SurrenderAI();
							}
						}
					}
				}
				break;
			}
		}
	}

	if (DeathAI == 2)
	{
		WhoInit();
		TroopsInit();

		GameEndTrueSave();
		WH->SetResultWidgetVisible(true, 1);
		WH->SetResultWidgetAllOccupy();
	}
}

void AC_WorldGameMode::SetAllPreTroops()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), StructureActor);

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			CurStructure->SetPreTroops();
		}
	}
}

void AC_WorldGameMode::LoadGameInfo()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (!WGS)return;

	if (UGameplayStatics::DoesSaveGameExist(TEXT("GameInfoSlot"), 0))
	{
		UC_GameInfoSaveGame* LoadGameInstance = Cast<UC_GameInfoSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("GameInfoSlot"), 0));

		WGS->Turn = LoadGameInstance->CurTurn;
		WGS->CurDifficulty = LoadGameInstance->CurDifficulty;
		WGS->CurGameTurnMode = LoadGameInstance->CurGameTurnMode;
		WGS->Tribes = LoadGameInstance->CurTribes;
		WGS->IsAIOneLose = LoadGameInstance->IsAIOneLose;
		WGS->IsAITwoLose = LoadGameInstance->IsAITwoLose;

		for (int i = 0; i < LoadGameInstance->SaveTroopInfo.Num(); ++i)
		{
			FindBaseStructure(LoadGameInstance->SaveTroopInfo[i]);	
		}
	}
}

void AC_WorldGameMode::GameInfoSave()
{
	UC_OccupationGameInstance* OccupationGameInstance = GetGameInstance<UC_OccupationGameInstance>();
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (!WGS)return;
	UC_GameInfoSaveGame* SaveGameInstance = Cast<UC_GameInfoSaveGame>(UGameplayStatics::CreateSaveGameObject(UC_GameInfoSaveGame::StaticClass()));

	OccupationGameInstance->IsEnd = false;

	SaveGameInstance->IsEnd = OccupationGameInstance->IsEnd;
	SaveGameInstance->CurTurn = WGS->GetTurn();
	SaveGameInstance->CurDifficulty = WGS->CurDifficulty;
	SaveGameInstance->CurGameTurnMode = WGS->CurGameTurnMode;
	SaveGameInstance->CurTribes = WGS->Tribes;
	SaveGameInstance->IsAIOneLose = WGS->IsAIOneLose;
	SaveGameInstance->IsAITwoLose = WGS->IsAITwoLose;

	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), StructureActor);

	int i = 0;

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			SaveGameInstance->SaveTroopInfo[i].TagName = CurStructure->Tags[0];
			SaveGameInstance->SaveTroopInfo[i].PlayerTroops = CurStructure->TroopInfo.PlayerTroops;
			SaveGameInstance->SaveTroopInfo[i].AI1Troops = CurStructure->TroopInfo.AI1Troops;
			SaveGameInstance->SaveTroopInfo[i].AI2Troops = CurStructure->TroopInfo.AI2Troops;
			SaveGameInstance->SaveTroopInfo[i].PrePlTroops = CurStructure->TroopInfo.PrePTroops;
			SaveGameInstance->SaveTroopInfo[i].PreAI1Troops = CurStructure->TroopInfo.PreAI1Troops;
			SaveGameInstance->SaveTroopInfo[i].PreAI2Troops = CurStructure->TroopInfo.PreAI2Troops;
			SaveGameInstance->SaveTroopInfo[i].Who = CurStructure->TroopInfo.Who;
		}
		++i;
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("GameInfoSlot"), 0);
}

void AC_WorldGameMode::FindBaseStructure(FBaseStructureInfo _LoadInfo)
{
	FName TagName = _LoadInfo.TagName;

	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TagName, StructureActor);

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			CurStructure->TroopInfo.PlayerTroops = _LoadInfo.PlayerTroops;
			CurStructure->TroopInfo.AI1Troops = _LoadInfo.AI1Troops;
			CurStructure->TroopInfo.AI2Troops = _LoadInfo.AI2Troops;
			CurStructure->TroopInfo.PrePTroops = _LoadInfo.PrePlTroops;
			CurStructure->TroopInfo.PreAI1Troops = _LoadInfo.PreAI1Troops;
			CurStructure->TroopInfo.PreAI2Troops = _LoadInfo.PreAI2Troops;
			CurStructure->TroopInfo.Who = _LoadInfo.Who;
		}
	}
}

void AC_WorldGameMode::GameEndTrueSave()
{
	UC_OccupationGameInstance* OccupationGameInstance = GetGameInstance<UC_OccupationGameInstance>();
	OccupationGameInstance->IsEnd = true;

	UC_GameInfoSaveGame* SaveGameInstance = Cast<UC_GameInfoSaveGame>(UGameplayStatics::CreateSaveGameObject(UC_GameInfoSaveGame::StaticClass()));
	
	SaveGameInstance->IsEnd = OccupationGameInstance->IsEnd;

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("GameInfoSlot"), 0);
}

void AC_WorldGameMode::OccupationColor()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_BaseStructure::StaticClass(), StructureActor);

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			CurStructure->WhoOccpyAndTerritoryAndTribe(CurStructure->TroopInfo.Who);
		}
	}
}
