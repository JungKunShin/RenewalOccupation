// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_PauseWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerController/C_WorldPlayerController.h"
#include "GameMode/C_WorldGameMode.h"
#include "HUD/C_WorldHUD.h"

void UWC_PauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ResumeButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnResumeClicked);
	SaveButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnPauseSaveClicked);
	SettingButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnSettingClicked);
	PauseTitleBackButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnPauseTitleBackClicked);
	ExitButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnExitClicked);

	DisplayButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnWorldDisplayClicked);
	VolumeButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnWorldVolumeClicked);
	PauseBackButton->OnClicked.AddDynamic(this, &UWC_PauseWidget::OnPauseBackClicked);

}

void UWC_PauseWidget::OnResumeClicked()
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AC_WorldHUD* WH = Cast< AC_WorldHUD>(PC->GetHUD());
	if (!WH)return;

	WH->SetPauseWidgetVisible(false);

	WidgetButtonSoundInit();
}

void UWC_PauseWidget::OnPauseSaveClicked()
{
	WidgetButtonSoundInit();

	AC_WorldGameMode* WGM = Cast<AC_WorldGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	WGM->GameInfoSave();
}

void UWC_PauseWidget::OnSettingClicked()
{
	WidgetButtonSoundInit();

	SetPauseWidgetIndex(1);
}

void UWC_PauseWidget::OnPauseTitleBackClicked()
{
	WidgetButtonSoundInit();

	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("/Game/Level/Title.umap")));
}

void UWC_PauseWidget::OnExitClicked()
{
	WidgetButtonSoundInit();

	if (APlayerController* PC = GetOwningPlayer())
	{
		UKismetSystemLibrary::QuitGame(this, PC, EQuitPreference::Quit, false);
	}
}

void UWC_PauseWidget::OnWorldDisplayClicked()
{
	WidgetButtonSoundInit();

	SetSettingsWidgetIndex(0);
}

void UWC_PauseWidget::OnWorldVolumeClicked()
{
	WidgetButtonSoundInit();

	SetSettingsWidgetIndex(1);
}

void UWC_PauseWidget::OnPauseBackClicked()
{
	BackButtonSoundInit();

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AC_WorldPlayerController* WPC = Cast< AC_WorldPlayerController>(PC);
	WPC->SaveSoundSettings(); // 음량 정보 저장

	SetSettingsWidgetIndex(0);
	SetPauseWidgetIndex(0);
}

void UWC_PauseWidget::SetPauseWidgetIndex(int32 _CurSwitchNum)
{
	PauseTotalWidgetSwitcher->SetActiveWidgetIndex(_CurSwitchNum);
}

void UWC_PauseWidget::SetSettingsWidgetIndex(int32 _CurSwitchNum)
{
	PauseSettingWidgetSwitcher->SetActiveWidgetIndex(_CurSwitchNum);
}
