// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/C_BaseStructure.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerController/C_WorldPlayerController.h"
#include "HUD/C_WorldHUD.h"
#include "GameState/C_WorldGameState.h"

AC_BaseStructure::AC_BaseStructure()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	StructureMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StructureMesh"));
	StructureMesh->SetupAttachment(SceneRoot);
	/*RootComponent = StructureMesh;*/

	StructureMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StructureMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	StructureMesh->SetGenerateOverlapEvents(true);
	StructureMesh->SetNotifyRigidBodyCollision(true);

	KoreaComp = CreateDefaultSubobject<UChildActorComponent>(TEXT("KoreaComp"));
	KoreaComp->SetupAttachment(SceneRoot);

	EgyptComp = CreateDefaultSubobject<UChildActorComponent>(TEXT("EgyptComp"));
	EgyptComp->SetupAttachment(SceneRoot);

	ChinaComp = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChinaComp"));
	ChinaComp->SetupAttachment(SceneRoot);
}

void AC_BaseStructure::BeginPlay()
{
	Super::BeginPlay();

	InitTribeStructure();

	UMaterialInterface* BaseMatMesh = StructureMesh->GetMaterial(0); // 슬롯 0 기준(얼굴색)
	DynMaterialMesh = UMaterialInstanceDynamic::Create(BaseMatMesh, this);
	StructureMesh->SetMaterial(0, DynMaterialMesh);

	StructureMesh->OnClicked.AddDynamic(this, &AC_BaseStructure::OnStructureClicked);
	StructureMesh->OnBeginCursorOver.AddDynamic(this, &AC_BaseStructure::OnStructureBeginCursorOver);
	StructureMesh->OnEndCursorOver.AddDynamic(this, &AC_BaseStructure::OnStructureEndCursorOver);
}

EWho AC_BaseStructure::WhoWin()
{
	if (TroopInfo.PlayerTroops > TroopInfo.AI1Troops && TroopInfo.PlayerTroops>TroopInfo.AI2Troops)//플레이어 승리
	{
		OverWhelmJudgement(TroopInfo.PlayerTroops, TroopInfo.AI1Troops, TroopInfo.AI2Troops);
		return EWho::Player;
	}
	else if (TroopInfo.AI1Troops > TroopInfo.PlayerTroops && TroopInfo.AI1Troops > TroopInfo.AI2Troops)//AI1 승리
	{
		OverWhelmJudgement(TroopInfo.AI1Troops, TroopInfo.PlayerTroops, TroopInfo.AI2Troops);
		return EWho::AIOne;
	}
	else if (TroopInfo.AI2Troops > TroopInfo.AI1Troops && TroopInfo.AI2Troops > TroopInfo.PlayerTroops)//AI2 승리
	{
		OverWhelmJudgement(TroopInfo.AI2Troops, TroopInfo.PlayerTroops, TroopInfo.AI1Troops);
		return EWho::AITwo;
	}
	else if (TroopInfo.PlayerTroops > TroopInfo.AI1Troops && TroopInfo.AI2Troops > TroopInfo.AI1Troops
		&&TroopInfo.PlayerTroops== TroopInfo.AI2Troops)//플레이어, AI1 동률
	{
		int32 RandomInt = FMath::RandRange(1, 2);
		if (RandomInt==1)
		{
			return EWho::Player;
		}
		else
		{
			return EWho::AITwo;
		}
	}
	else if (TroopInfo.PlayerTroops > TroopInfo.AI2Troops && TroopInfo.AI1Troops > TroopInfo.AI2Troops
		&& TroopInfo.PlayerTroops == TroopInfo.AI1Troops)//플레이어, AI2 동률
	{
		int32 RandomInt = FMath::RandRange(1, 2);
		if (RandomInt == 1)
		{
			return EWho::Player;
		}
		else
		{
			return EWho::AIOne;
		}
	}
	else if (TroopInfo.AI1Troops>TroopInfo.PlayerTroops&& TroopInfo.AI2Troops > TroopInfo.PlayerTroops
		&& TroopInfo.AI1Troops == TroopInfo.AI2Troops)//AI1,AI2 동률
	{
		int32 RandomInt = FMath::RandRange(1, 2);
		if (RandomInt == 1)
		{
			return EWho::AIOne;
		}
		else
		{
			return EWho::AITwo;
		}
	}
	else if (TroopInfo.PlayerTroops && TroopInfo.PlayerTroops == TroopInfo.AI1Troops && TroopInfo.PlayerTroops == TroopInfo.AI2Troops)//0이 아닌 셋다 동률
	{
		int32 RandomInt = FMath::RandRange(1, 3);
		if (RandomInt == 1)
		{
			return EWho::Player;
		}
		else if(RandomInt==2)
		{
			return EWho::AIOne;
		}
		else
		{
			return EWho::AITwo;
		}
	}
	else//셋다 0
	{
		return EWho::None;
	}
}

void AC_BaseStructure::PlayersWar()
{
	switch (WhoWin())
	{
	case EWho::Player:
		BackBaseCamp(TroopInfo.AI1Troops, FName("BCB"));
		BackBaseCamp(TroopInfo.AI2Troops, FName("BCG"));
		TroopInfo.Who = EWho::Player;
		WhoOccpyAndTerritoryAndTribe(EWho::Player);
		break;
	case EWho::AIOne:
		BackBaseCamp(TroopInfo.PlayerTroops, FName("BCR"));
		BackBaseCamp(TroopInfo.AI2Troops, FName("BCG"));
		TroopInfo.Who = EWho::AIOne;
		WhoOccpyAndTerritoryAndTribe(EWho::AIOne);
		break;
	case EWho::AITwo:
		BackBaseCamp(TroopInfo.PlayerTroops, FName("BCR"));
		BackBaseCamp(TroopInfo.AI1Troops, FName("BCB"));
		TroopInfo.Who = EWho::AITwo;
		WhoOccpyAndTerritoryAndTribe(EWho::AITwo);
		break;
	case EWho::None:
	default:
		break;
	}
}

void AC_BaseStructure::WhoOccpyAndTerritoryAndTribe(EWho _Who)
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	if (!WGS)return;

	EGameTribe WinTribe;

	switch(_Who)
	{
	case EWho::Player:
		WinTribe = WGS->Tribes[0];
		break;
	case EWho::AIOne:
		WinTribe = WGS->Tribes[1];
		break;
	case EWho::AITwo:
		WinTribe = WGS->Tribes[2];
		break;
	case EWho::None:
	default:
		return;
	}

	switch (WinTribe)
	{
	case EGameTribe::Korea:
		KoreaComp->SetHiddenInGame(false);
		ChinaComp->SetHiddenInGame(true);
		EgyptComp->SetHiddenInGame(true);
		WinTribeColor(EGameTribe::Korea);
		break;
	case EGameTribe::China:
		KoreaComp->SetHiddenInGame(true);
		ChinaComp->SetHiddenInGame(false);
		EgyptComp->SetHiddenInGame(true);
		WinTribeColor(EGameTribe::China);
		break;
	case EGameTribe::Egypt:
		KoreaComp->SetHiddenInGame(true);
		ChinaComp->SetHiddenInGame(true);
		EgyptComp->SetHiddenInGame(false);
		WinTribeColor(EGameTribe::Egypt);
		break;
	default:
		break;
	}
}

void AC_BaseStructure::WinTribeColor(EGameTribe _Tribe)
{
	switch (_Tribe)
	{
	case EGameTribe::Korea:
		DynMaterialMesh->SetVectorParameterValue("Color", FLinearColor::Blue);
		break;
	case EGameTribe::China:
		DynMaterialMesh->SetVectorParameterValue("Color", FLinearColor::Red);
		break;
	case EGameTribe::Egypt:
		DynMaterialMesh->SetVectorParameterValue("Color", FLinearColor::Yellow);
		break;
	default:
		break;
	}
}

void AC_BaseStructure::OverWhelmJudgement(int32& _Winner, int32& _LoserOne, int32& _LoserTwo)
{
	if (!_LoserOne && !_LoserTwo)return;
	if (_Winner / (_LoserOne + _LoserTwo) < 2)return;

	if (_LoserOne)
	{
		_LoserOne = 0;
	}
	if (_LoserTwo)
	{
		_LoserTwo = 0;
	}
}

void AC_BaseStructure::BackBaseCamp(int32& _Loser, FName _TagName)
{
	TArray<AActor*> BaseCampActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), _TagName, BaseCampActor);

	for (AActor* MyActor : BaseCampActor)
	{
		AC_BaseStructure* BaseTent = Cast<AC_BaseStructure>(MyActor);
		if (BaseTent)
		{
			if (_TagName == FName("BCR"))
			{
				BaseTent->TroopInfo.PlayerTroops += _Loser;
			}
			else if (_TagName == FName("BCB"))
			{
				BaseTent->TroopInfo.AI1Troops += _Loser;
			}
			else if (_TagName == FName("BCG"))
			{
				BaseTent->TroopInfo.AI2Troops += _Loser;
			}
			_Loser = 0;
			break;
		}
	}
}

void AC_BaseStructure::AIOneMove()
{
	if (TroopInfo.Who != EWho::AIOne)return;

	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	switch (WGS->CurDifficulty)
	{
	default:
	case EGameDifficulty::Easy:
		AIEasyMode(TroopInfo.AI1Troops, EWho::AIOne);
		break;
	case EGameDifficulty::Normal:
		break;
	case EGameDifficulty::Hard:
		break;
	}
}

void AC_BaseStructure::AITwoMove()
{
	if (TroopInfo.Who != EWho::AITwo)return;

	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();

	switch (WGS->CurDifficulty)
	{
	default:
	case EGameDifficulty::Easy:
		AIEasyMode(TroopInfo.AI2Troops, EWho::AITwo);
		break;
	case EGameDifficulty::Normal:
		break;
	case EGameDifficulty::Hard:
		break;
	}

}

void AC_BaseStructure::AIEasyMode(int32& _AITroops, EWho _Who)
{
	int32 IsAttack = FMath::RandRange(0,1);
	
	if (!IsAttack)return; //0이면 수비, 1이면 공격

	if (_AITroops) //병력이 하나라도 있으면 실행
	{
		for (int i = 0; i < Surroundings.Num(); ++i)
		{
			int32 DividedTroops = FMath::RandRange(0, _AITroops); //무작위 병력 분배
			
			if (DividedTroops > _AITroops)continue;//_AITroops가 계속 변해서 괜찮을 거 같지만, 혹시 모르니

			_AITroops -= DividedTroops; // 현재 거점에서의 병력 차감
			AC_BaseStructure* AttackedPlace =Cast< AC_BaseStructure>( Surroundings[i]); //주변 거점으로 순차적으로 분배
			if (AttackedPlace)
			{
				if (_Who == EWho::AIOne)
				{
					AttackedPlace->TroopInfo.AI1Troops += DividedTroops;
				}
				else if (_Who == EWho::AITwo)
				{
					AttackedPlace->TroopInfo.AI2Troops += DividedTroops;
				}
			}
		}
	}
}

void AC_BaseStructure::SetPreTroops()
{
	TroopInfo.PrePTroops = TroopInfo.PlayerTroops;
	TroopInfo.PreAI1Troops = TroopInfo.AI1Troops;
	TroopInfo.PreAI2Troops = TroopInfo.AI2Troops;
}

void AC_BaseStructure::OnStructureClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (TroopInfo.Who != EWho::Player)return;

	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	WGS->SetStructure(this);

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AC_WorldPlayerController* WPC = Cast<AC_WorldPlayerController>(PC);
	if (!WPC)return;
	AC_WorldHUD* WH = Cast< AC_WorldHUD>(WPC->GetHUD());
	if (!WH)return;

	WH->SetAttackOperationWidgetVisible(true);
}

void AC_BaseStructure::OnStructureBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (TroopInfo.Who != EWho::Player)return;

	StructureMesh->SetRenderCustomDepth(true);
	StructureMesh->SetCustomDepthStencilValue(2); // 포스트 프로세스 머티리얼에서 2값 처리	
}

void AC_BaseStructure::OnStructureEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (TroopInfo.Who != EWho::Player)return;

	StructureMesh->SetRenderCustomDepth(false);
}

void AC_BaseStructure::InitTribeStructure()
{
	KoreaComp->SetHiddenInGame(true);
	EgyptComp->SetHiddenInGame(true);
	ChinaComp->SetHiddenInGame(true);
}

void AC_BaseStructure::SurrenderAI()
{
	InitTribeStructure();
	DynMaterialMesh->SetVectorParameterValue("Color", FLinearColor::White);
}
