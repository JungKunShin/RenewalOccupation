// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_PlayingWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "GameState/C_WorldGameState.h"
#include "GameMode/C_WorldGameMode.h"
#include "HUD/C_WorldHUD.h"
#include "Kismet/GameplayStatics.h"

void UWC_PlayingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GetWorld()->GetTimerManager().ClearTimer(TextTH);
	GetWorld()->GetTimerManager().SetTimer(TextTH, this, &UWC_PlayingWidget::DelayInit, 0.3f, false);

	TurnEndButton->OnClicked.AddDynamic(this, &UWC_PlayingWidget::OnTurnEndButtonClicked);
	InstructionButton->OnClicked.AddDynamic(this, &UWC_PlayingWidget::OnInstructionButtonClicked);
}

void UWC_PlayingWidget::OnTurnEndButtonClicked()
{
	TurnEndButton->SetVisibility(ESlateVisibility::Hidden);
	TurnEndBorder->SetVisibility(ESlateVisibility::Hidden);

	GetWorld()->GetTimerManager().SetTimer(TurnEndTH, this, &UWC_PlayingWidget::DelayEndTurn, 1.5f, false);

	WidgetButtonSoundInit();

	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (!WGS)return;
	AC_WorldGameMode* WGM = Cast<AC_WorldGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!WGM)return;

	WGM->GameProcedure();

	Text_CurTurn->SetText(FText::AsNumber(WGS->GetTurn()));
	Text_CurPlOccupation->SetText(FText::AsNumber(WGS->Occupation[0]));
	Text_CurAI1Occupation->SetText(FText::AsNumber(WGS->Occupation[1]));
	Text_CurAI2Occupation->SetText(FText::AsNumber(WGS->Occupation[2]));
	Text_TotalPlTroops->SetText(FText::AsNumber(WGS->TotalTroops[0]));
	Text_TotalAI1Troops->SetText(FText::AsNumber(WGS->TotalTroops[1]));
	Text_TotalAI2Troops->SetText(FText::AsNumber(WGS->TotalTroops[2]));
}

void UWC_PlayingWidget::OnInstructionButtonClicked()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AC_WorldHUD* WH = Cast< AC_WorldHUD>(PC->GetHUD());
	if (!WH)return;

	WH->SetInstructionWidgetVisible(true);
	WH->SetInstructionCloseButton();
}

void UWC_PlayingWidget::DelayEndTurn()
{
	TurnEndButton->SetVisibility(ESlateVisibility::Visible);
	TurnEndBorder->SetVisibility(ESlateVisibility::Visible);
}

void UWC_PlayingWidget::DelayInit()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (!WGS)return;
	AC_WorldGameMode* WGM = Cast<AC_WorldGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!WGM)return;

	WGM->WhoInit();
	WGM->TroopsInit();

	Text_CurPlOccupation->SetText(FText::AsNumber(WGS->Occupation[0]));
	Text_CurAI1Occupation->SetText(FText::AsNumber(WGS->Occupation[1]));
	Text_CurAI2Occupation->SetText(FText::AsNumber(WGS->Occupation[2]));
	Text_TotalPlTroops->SetText(FText::AsNumber(WGS->TotalTroops[0]));
	Text_TotalAI1Troops->SetText(FText::AsNumber(WGS->TotalTroops[1]));
	Text_TotalAI2Troops->SetText(FText::AsNumber(WGS->TotalTroops[2]));
	Text_CurTurn->SetText(FText::AsNumber(WGS->GetTurn()));
	GetWorld()->GetTimerManager().ClearTimer(TextTH);
}
