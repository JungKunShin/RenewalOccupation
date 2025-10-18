// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/C_BaseActor.h"
#include "Engine/DataTable.h"
#include "GameState/C_BaseGameState.h"
#include "C_BaseStructure.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWho : uint8
{
	Player,
	AIOne,
	AITwo,
	None
};

USTRUCT(BlueprintType)
struct FStructureInfo : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY()
	int32 PlayerTroops = 0;

	UPROPERTY()
	int32 AI1Troops = 0;

	UPROPERTY()
	int32 AI2Troops = 0;

	UPROPERTY()
	int32 PrePTroops = 0;

	UPROPERTY()
	int32 PreAI1Troops = 0;

	UPROPERTY()
	int32 PreAI2Troops = 0;

	UPROPERTY()
	EWho Who = EWho::None; //º“¿Ø±«
};

UCLASS()
class OCCUPATION_API AC_BaseStructure : public AC_BaseActor
{
	GENERATED_BODY()

public:
	AC_BaseStructure();

protected:
	virtual void BeginPlay()override;

public:
	EWho WhoWin();

	void PlayersWar();

	void WhoOccpyAndTerritoryAndTribe(EWho _Who);

	void WinTribeColor(EGameTribe _Tribe);

	void OverWhelmJudgement(int32& _Winner,int32& _LoserOne,int32& _LoserTwo);

	void BackBaseCamp(int32& _Loser,FName _TagName);

	void AIOneMove();

	void AITwoMove();

	void AIEasyMode(int32& _AITroops,EWho _Who);

	void SetPreTroops();

	UFUNCTION()
	void OnStructureClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION()
	void OnStructureBeginCursorOver(UPrimitiveComponent* TouchedComponent);
	UFUNCTION()
	void OnStructureEndCursorOver(UPrimitiveComponent* TouchedComponent);

	void InitTribeStructure();

	void SurrenderAI();

public:
	FStructureInfo TroopInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> Surroundings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> A1Forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> A1Backward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> A2Forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> A2Backward;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StructureMesh;

	UPROPERTY(VisibleAnywhere)
	UChildActorComponent* KoreaComp;

	UPROPERTY(VisibleAnywhere)
	UChildActorComponent* EgyptComp;

	UPROPERTY(VisibleAnywhere)
	UChildActorComponent* ChinaComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY()
	UMaterialInstanceDynamic* DynMaterialMesh;
};
