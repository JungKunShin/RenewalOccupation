// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_ResultWidget.h"
#include "MediaPlayer.h"
#include "MediaSoundComponent.h"
#include "FileMediaSource.h"
#include "Kismet/GameplayStatics.h"
#include "Manager/C_SoundManager.h"

#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

#include "GameInstance/C_OccupationGameInstance.h"
#include "GameState/C_WorldGameState.h"
#include "PlayerController/C_WorldPlayerController.h"
#include "HUD/C_WorldHUD.h"
#include "SaveGame/C_GameInfoSaveGame.h"

void UWC_ResultWidget::NativeConstruct()
{
    Super::NativeConstruct();

    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    AC_WorldPlayerController* WPC = Cast< AC_WorldPlayerController>(PC);
    AC_WorldHUD* WH = Cast< AC_WorldHUD>(PC->GetHUD());

    if (WPC)
    {
        WPC->GetSoundManager()->StopBGM();
    }

    if (WH)
    {
        if (WH->MediaSound)
        {
            WH->MediaSound->SetVolumeMultiplier(WPC->GetSoundManager()->UIVolume);
            WH->MediaSound->SetMediaPlayer(MediaPlayer);
        }
    }

    TitleBackButton->OnClicked.AddDynamic(this, &UWC_ResultWidget::OnTitleBackClicked);

    InitTextBlock();
}

void UWC_ResultWidget::WinResult(int32 _Result)
{
    MediaPlayer->OnEndReached.AddDynamic(this, &UWC_ResultWidget::ResultVideoEnd);

    switch (_Result)
    {
    case 1:
        if (MediaPlayer && WinSource)
        {
            Text_Win->SetVisibility(ESlateVisibility::Visible);
            MediaPlayer->OpenSource(WinSource);
            MediaPlayer->Play();
        }
        break;
    case 2:
        if (MediaPlayer && LoseSource)
        {
            Text_Lose->SetVisibility(ESlateVisibility::Visible);
            MediaPlayer->OpenSource(LoseSource);
            MediaPlayer->Play();
        }
        break;
    case 3:
        if (MediaPlayer && DrawSource)
        {
            Text_Draw->SetVisibility(ESlateVisibility::Visible);
            MediaPlayer->OpenSource(DrawSource);
            MediaPlayer->Play();
        }
        break;
    default:
        break;
    }
}

void UWC_ResultWidget::SetResultWidgetIndex(int32 _CurSwitchNum)
{
    ResultWidgetSwitcher->SetActiveWidgetIndex(_CurSwitchNum);
}

void UWC_ResultWidget::ResultVideoEnd()
{
    SetResultWidgetIndex(1);
    if (MediaPlayer)
    {
        MediaPlayer->Close();
    }
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    AC_WorldHUD* WH = Cast< AC_WorldHUD>(PC->GetHUD());
    if (!WH)return;

    WH->SetInputMode(EInputMode::UIOnly, true);
}

void UWC_ResultWidget::OnTitleBackClicked()
{
    WidgetButtonSoundInit();

    UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("/Game/Level/Title.umap")));
}

void UWC_ResultWidget::InitTextBlock()
{
    Text_Win->SetVisibility(ESlateVisibility::Hidden);
    Text_Lose->SetVisibility(ESlateVisibility::Hidden);
    Text_Draw->SetVisibility(ESlateVisibility::Hidden);
    Text_PlCollapse->SetVisibility(ESlateVisibility::Hidden);
    Text_AIOneCollapse->SetVisibility(ESlateVisibility::Hidden);
    Text_AITwoCollapse->SetVisibility(ESlateVisibility::Hidden);

    AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
    if (!WGS)return;

    Text_MyOccupation->SetText(FText::AsNumber(WGS->Occupation[0]));
    Text_MyTotalTroops->SetText(FText::AsNumber(WGS->TotalTroops[0]));
    Text_AIOneOccupation->SetText(FText::AsNumber(WGS->Occupation[1]));
    Text_AIOneTotalTroops->SetText(FText::AsNumber(WGS->TotalTroops[1]));
    Text_AITwoOccupation->SetText(FText::AsNumber(WGS->Occupation[2]));
    Text_AITwoTotalTroops->SetText(FText::AsNumber(WGS->TotalTroops[2]));

    Text_TakedTurn->SetText(FText::AsNumber(WGS->GetTurn()-1));
    Text_WinGameCondition->SetText(FText::FromString(TEXT("턴 승리")));

    switch (WGS->CurDifficulty)
    {
    case EGameDifficulty::Easy:
        Text_GameDifficulty->SetText(FText::FromString(TEXT("Easy")));
        break;
    case EGameDifficulty::Normal:
        Text_GameDifficulty->SetText(FText::FromString(TEXT("Normal")));
        break;
    case EGameDifficulty::Hard:
        Text_GameDifficulty->SetText(FText::FromString(TEXT("Hard")));
        break;
    default:
        break;
    }

    switch (WGS->CurGameTurnMode)
    {
    case EGameTurn::Twenty:
        Text_GameTurnMode->SetText(FText::FromString(TEXT("20턴 모드")));
        Text_TurnEnd->SetText(FText::AsNumber(20));
        break;
    case EGameTurn::Thirty:
        Text_GameTurnMode->SetText(FText::FromString(TEXT("30턴 모드")));
        Text_TurnEnd->SetText(FText::AsNumber(30));
        break;
    case EGameTurn::Forty:
        Text_GameTurnMode->SetText(FText::FromString(TEXT("40턴 모드")));
        Text_TurnEnd->SetText(FText::AsNumber(40));
        break;
    case EGameTurn::Infinite:
        Text_GameTurnMode->SetText(FText::FromString(TEXT("무제한 모드")));
        Text_TurnEnd->SetText(FText::FromString(TEXT("무제한")));
        break;
    default:
        break;
    }
 
    TribeDistinguish(WGS->Tribes[0], Text_PlayerTribe);
    TribeDistinguish(WGS->Tribes[1], Text_AIOneTribe);
    TribeDistinguish(WGS->Tribes[2], Text_AITwoTribe);

    if (WGS->IsAIOneLose)
    {
        Text_AIOneCollapse->SetVisibility(ESlateVisibility::Visible);
    }
    if (WGS->IsAITwoLose)
    {
        Text_AITwoCollapse->SetVisibility(ESlateVisibility::Visible);
    }
}

void UWC_ResultWidget::PlayerLose()
{
    Text_PlCollapse->SetVisibility(ESlateVisibility::Visible);
}

void UWC_ResultWidget::AllOccupyWin()
{
    Text_WinGameCondition->SetText(FText::FromString(TEXT("정복 승리")));
}

void UWC_ResultWidget::TribeDistinguish(EGameTribe _Tribe, UTextBlock* _TextBlock)
{
    switch (_Tribe)
    {
    case EGameTribe::Korea:
        _TextBlock->SetText(FText::FromString(TEXT("한국")));
        break;
    case EGameTribe::China:
        _TextBlock->SetText(FText::FromString(TEXT("중국")));
        break;
    case EGameTribe::Egypt:
        _TextBlock->SetText(FText::FromString(TEXT("이집트")));
        break;
    default:
        break;
    }
}
