// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/C_BaseHUD.h"
#include "C_WorldHUD.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API AC_WorldHUD : public AC_BaseHUD
{
	GENERATED_BODY()
	
public:
	AC_WorldHUD();

protected:
	virtual void BeginPlay()override;

public:
	void SetAttackOperationWidgetVisible(bool bOnShow);

	void SetPlayingWidgetVisible(bool bOnShow);

	void SetMapWidgetVisible(bool bOnShow);

	void SetPauseWidgetVisible(bool bOnShow);

	void SetResultWidgetVisible(bool bOnShow,int32 _Result=0);

	void SetResultWidgetPlayerLose();

	void SetResultWidgetAllOccupy();

	void SetInstructionWidgetVisible(bool bOnShow);

	void SetInstructionCloseButton();
public:
	UPROPERTY(BlueprintReadWrite)
	class UWC_AttackOperationWidget* AttackOperationWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> AttackOperationWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	class UWC_PlayingWidget* PlayingWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> PlayingWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	class UWC_MapWidget* MapWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> MapWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	class UWC_PauseWidget* PauseWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	class UWC_ResultWidget* ResultWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> ResultWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Video")
	class UMediaSoundComponent* MediaSound;

	UPROPERTY(BlueprintReadWrite)
	class UWC_InstructionWidget* InstructionWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InstructionWidgetClass;
};
