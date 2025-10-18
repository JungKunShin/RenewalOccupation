// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_InstructionWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "HUD/C_WorldHUD.h"
#include "PlayerController/C_WorldPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Manager/C_SoundManager.h"

void UWC_InstructionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BeginOpenSound();

	CloseButton->OnClicked.AddDynamic(this, &UWC_InstructionWidget::OnInstructionCloseClicked);
	GameRuleButton->OnClicked.AddDynamic(this, &UWC_InstructionWidget::OnGameRuleClicked);
	GameDifficultyButton->OnClicked.AddDynamic(this, &UWC_InstructionWidget::OnGameDifficultyClicked);
	GameTurnModeButton->OnClicked.AddDynamic(this, &UWC_InstructionWidget::OnGameTurnClicked);
	GameTribeButton->OnClicked.AddDynamic(this, &UWC_InstructionWidget::OnGameTribeClicked);

	CloseButton->SetVisibility(ESlateVisibility::Hidden);
	GameRuleButton->SetBackgroundColor(FLinearColor(0.1f, 0.1f, 0.1f, 1.0f));
}

void UWC_InstructionWidget::OnInstructionCloseClicked()
{
	BackButtonSoundInit();
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AC_WorldHUD* WH = Cast<AC_WorldHUD>(PC->GetHUD());

	WH->SetInstructionWidgetVisible(false);
}

void UWC_InstructionWidget::OnGameRuleClicked()
{
	InitGrayButtonColor();
	GameRuleButton->SetBackgroundColor(FLinearColor(0.1f, 0.1f, 0.1f, 1.0f));
	WidgetButtonSoundInit();
	SetInstructionWidgetIndex(0);
}

void UWC_InstructionWidget::OnGameDifficultyClicked()
{
	InitGrayButtonColor();
	GameDifficultyButton->SetBackgroundColor(FLinearColor(0.1f, 0.1f, 0.1f, 1.0f));
	WidgetButtonSoundInit();
	SetInstructionWidgetIndex(1);
}

void UWC_InstructionWidget::OnGameTurnClicked()
{
	InitGrayButtonColor();
	GameTurnModeButton->SetBackgroundColor(FLinearColor(0.1f, 0.1f, 0.1f, 1.0f));
	WidgetButtonSoundInit();
	SetInstructionWidgetIndex(2);
}

void UWC_InstructionWidget::OnGameTribeClicked()
{
	InitGrayButtonColor();
	GameTribeButton->SetBackgroundColor(FLinearColor(0.1f, 0.1f, 0.1f, 1.0f));
	WidgetButtonSoundInit();
	SetInstructionWidgetIndex(3);
}

void UWC_InstructionWidget::SetInstructionWidgetIndex(int32 _CurSwitchNum)
{
	InstructionSwitcher->SetActiveWidgetIndex(_CurSwitchNum);
}

void UWC_InstructionWidget::InitGrayButtonColor()
{
	GameRuleButton->SetBackgroundColor(FLinearColor(0.2f, 0.2f, 0.2f, 0.8f));
	GameDifficultyButton->SetBackgroundColor(FLinearColor(0.2f, 0.2f, 0.2f, 0.8f));
	GameTurnModeButton->SetBackgroundColor(FLinearColor(0.2f, 0.2f, 0.2f, 0.8f));
	GameTribeButton->SetBackgroundColor(FLinearColor(0.2f, 0.2f, 0.2f, 0.8f));
}

void UWC_InstructionWidget::BeginOpenSound()
{
	if (OpenSound)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		AC_WorldPlayerController* WPC = Cast< AC_WorldPlayerController>(PC);

		if (!WPC)return;

		UGameplayStatics::PlaySound2D(this, OpenSound, WPC->GetSoundManager()->UIVolume, 1.0f);
	}
}

void UWC_InstructionWidget::SetCloseButton()
{
	CloseButton->SetVisibility(ESlateVisibility::Visible);
}
