// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_TitleWidget.h"
#include "Components/Button.h"
#include "Components/ComboBoxString.h"
#include "Components/WidgetSwitcher.h"

#include "GameInstance/C_OccupationGameInstance.h"
#include "GameState/C_TitleGameState.h"
#include "GameMode/C_TitleGameMode.h"
#include "HUD/C_TitleHUD.h"
#include "SaveGame/C_GameInfoSaveGame.h"
#include "PlayerController/C_TitlePlayerController.h"
#include "Manager/C_SoundManager.h"

#include "Kismet/GameplayStatics.h"


void UWC_TitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	LoadButtonPossible();

	StartButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnTitleStartClicked);
	LoadButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnTitleLoadClicked);
	SettingButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnGameSettingsClicked);
	LevelChangeButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnLevelChangeClicked);
	GameInfoButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnGameInfoClicked);
	ExitButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnGameExitClicked);
	DisplayButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnDisplayClicked);
	VolumeButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnVolumeClicked);

	TitleBackDetailButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnTitleFirstBackClicked);
	TitleBackButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnTitleFirstBackClicked);
	TitleBackInfoButton->OnClicked.AddDynamic(this, &UWC_TitleWidget::OnTitleFirstBackClicked);

	Combo_DifficultyMode->AddOption(TEXT("Easy"));
	//Combo_DifficultyMode->AddOption(TEXT("Normal"));
	//Combo_DifficultyMode->AddOption(TEXT("Hard"));
	Combo_DifficultyMode->SetSelectedOption(TEXT("Easy"));
	Combo_DifficultyMode->OnSelectionChanged.AddDynamic(this, &UWC_TitleWidget::OnDifficultyModeChanged);

	Combo_TurnMode->AddOption(TEXT("20 턴"));
	Combo_TurnMode->AddOption(TEXT("30 턴"));
	Combo_TurnMode->AddOption(TEXT("40 턴"));
	Combo_TurnMode->AddOption(TEXT("무제한 모드"));
	Combo_TurnMode->SetSelectedOption(TEXT("20 턴"));
	Combo_TurnMode->OnSelectionChanged.AddDynamic(this, &UWC_TitleWidget::OnTurnModeChanged);

	Combo_Tribe->AddOption(TEXT("한국"));
	Combo_Tribe->AddOption(TEXT("중국"));
	Combo_Tribe->AddOption(TEXT("이집트"));
	Combo_Tribe->SetSelectedOption(TEXT("한국"));
	Combo_Tribe->OnSelectionChanged.AddDynamic(this, &UWC_TitleWidget::OnTribeChanged);

	StartButton->OnHovered.AddDynamic(this, &UWC_TitleWidget::OnButtonHovered);
	LoadButton->OnHovered.AddDynamic(this, &UWC_TitleWidget::OnButtonHovered);
	SettingButton->OnHovered.AddDynamic(this, &UWC_TitleWidget::OnButtonHovered);
	GameInfoButton->OnHovered.AddDynamic(this, &UWC_TitleWidget::OnButtonHovered);
	ExitButton->OnHovered.AddDynamic(this, &UWC_TitleWidget::OnButtonHovered);

}

void UWC_TitleWidget::OnDifficultyModeChanged(FString Selected, ESelectInfo::Type SelectionType)
{
	AC_TitleGameState* TGS = GetWorld()->GetGameState< AC_TitleGameState>();
	if (!TGS)return;

	if (Selected == TEXT("Easy"))
	{
		TGS->CurGameDifficulty = EGameDifficulty::Easy;
	}
	//else if (Selected == TEXT("Normal"))
	//{
	//	TGS->CurGameDifficulty = EGameDifficulty::Normal;
	//}
	//else if (Selected == TEXT("Hard"))
	//{
	//	TGS->CurGameDifficulty = EGameDifficulty::Hard;
	//}
}

void UWC_TitleWidget::OnTurnModeChanged(FString Selected, ESelectInfo::Type SelectionType)
{
	AC_TitleGameState* TGS = GetWorld()->GetGameState< AC_TitleGameState>();
	if (!TGS)return;

	if (Selected == TEXT("20 턴"))
	{
		TGS->CurGameTurn = EGameTurn::Twenty;
	}
	else if (Selected == TEXT("30 턴"))
	{
		TGS->CurGameTurn = EGameTurn::Thirty;
	}
	else if (Selected == TEXT("40 턴"))
	{
		TGS->CurGameTurn = EGameTurn::Forty;
	}
	else if (Selected == TEXT("무제한 모드"))
	{
		TGS->CurGameTurn = EGameTurn::Infinite;
	}
}

void UWC_TitleWidget::OnTribeChanged(FString Selected, ESelectInfo::Type SelectionType)
{
	AC_TitleGameState* TGS = GetWorld()->GetGameState< AC_TitleGameState>();
	if (!TGS)return;

	if (Selected == TEXT("한국"))
	{
		TGS->CurTribes[0] = EGameTribe::Korea;
	}
	else if (Selected == TEXT("중국"))
	{
		TGS->CurTribes[0] = EGameTribe::China;
	}
	else if (Selected == TEXT("이집트"))
	{
		TGS->CurTribes[0] = EGameTribe::Egypt;
	}
}

void UWC_TitleWidget::SetTitleWidgetIndex(int32 _CurSwitchNum)
{
	TitleWidgetSwitcher->SetActiveWidgetIndex(_CurSwitchNum);
}

void UWC_TitleWidget::SetDetailWidgetIndex(int32 _CurSwitchNum)
{
	DetailWidgetSwitcher->SetActiveWidgetIndex(_CurSwitchNum);
}

void UWC_TitleWidget::TitleInit()
{
	AC_TitleGameState* TGS = GetWorld()->GetGameState< AC_TitleGameState>();
	if (!TGS)return;

	TGS->CurGameTurn = EGameTurn::Twenty;
	TGS->CurGameDifficulty = EGameDifficulty::Easy;
}

void UWC_TitleWidget::OnTitleStartClicked()
{
	WidgetButtonSoundInit();

	SetTitleWidgetIndex(1);
}

void UWC_TitleWidget::OnTitleLoadClicked()
{
	WidgetButtonSoundInit();

	UC_OccupationGameInstance* OccupationGameInstance = GetGameInstance<UC_OccupationGameInstance>();
	if (OccupationGameInstance->IsEnd|| !UGameplayStatics::DoesSaveGameExist(TEXT("GameInfoSlot"), 0))return;
	
	OccupationGameInstance->IsLoad = true;
	
	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("/Game/Level/World.umap")));
}

void UWC_TitleWidget::OnLevelChangeClicked()
{
	WidgetButtonSoundInit();

	AC_TitleGameState* TGS = GetWorld()->GetGameState< AC_TitleGameState>();
	if (!TGS)return;
	AC_TitleGameMode* TGM = Cast<AC_TitleGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!TGM)return;

	TGM->AITribeChoice();

	UC_OccupationGameInstance* OccupationGameInstance = GetGameInstance<UC_OccupationGameInstance>();
	OccupationGameInstance->IsLoad = false;

	SaveEndFalse();
	OccupationGameInstance->SetNewGameInfo(TGS->CurGameDifficulty,TGS->CurGameTurn,TGS->CurTribes);

	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("/Game/Level/World.umap")));
}

void UWC_TitleWidget::OnGameSettingsClicked()
{
	WidgetButtonSoundInit();

	SetTitleWidgetIndex(2);
}

void UWC_TitleWidget::OnGameInfoClicked()
{
	WidgetButtonSoundInit();
	SetTitleWidgetIndex(3);
}

void UWC_TitleWidget::OnGameExitClicked()
{
	WidgetButtonSoundInit();

	if (APlayerController* PC = GetOwningPlayer())
	{
		UKismetSystemLibrary::QuitGame(this, PC, EQuitPreference::Quit, false);
	}
}

void UWC_TitleWidget::OnTitleFirstBackClicked()
{
	BackButtonSoundInit();

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AC_TitlePlayerController* TPC = Cast< AC_TitlePlayerController>(PC);
	TPC->SaveSoundSettings(); // 음량 정보 저장

	SetDetailWidgetIndex(0);
	SetTitleWidgetIndex(0);
}

void UWC_TitleWidget::OnDisplayClicked()
{
	WidgetButtonSoundInit();

	SetDetailWidgetIndex(0);
}

void UWC_TitleWidget::OnVolumeClicked()
{
	WidgetButtonSoundInit();

	SetDetailWidgetIndex(1);
}

void UWC_TitleWidget::OnButtonHovered()
{
	if (HoverSound)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		AC_TitlePlayerController* TPC = Cast< AC_TitlePlayerController>(PC);

		UGameplayStatics::PlaySound2D(this, HoverSound, TPC->GetSoundManager()->UIVolume, 1.0f);
	}
}

void UWC_TitleWidget::SaveEndFalse()
{
	UC_GameInfoSaveGame* SaveGameInstance = Cast<UC_GameInfoSaveGame>(UGameplayStatics::CreateSaveGameObject(UC_GameInfoSaveGame::StaticClass()));
	SaveGameInstance->IsEnd = false;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("GameInfoSlot"), 0);
}

void UWC_TitleWidget::LoadButtonPossible()
{
	UC_OccupationGameInstance* OccupationGameInstance = GetGameInstance<UC_OccupationGameInstance>();
	if (OccupationGameInstance->IsEnd|| !UGameplayStatics::DoesSaveGameExist(TEXT("GameInfoSlot"), 0))
	{
		LoadButton->SetColorAndOpacity(FLinearColor(0.4f, 0.4f, 0.4f, 0.9f));
	}
}
