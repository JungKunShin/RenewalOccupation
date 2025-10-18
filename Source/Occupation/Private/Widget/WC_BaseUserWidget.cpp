// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_BaseUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Manager/C_SoundManager.h"
#include "PlayerController/C_BasePlayerController.h"

void UWC_BaseUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	WidgetBeginSoundInit();
}

void UWC_BaseUserWidget::WidgetBeginSoundInit()
{
	if (BeginSound)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);

		UGameplayStatics::PlaySound2D(this, BeginSound, BPC->GetSoundManager()->UIVolume, 1.0f);
	}
}

void UWC_BaseUserWidget::WidgetButtonSoundInit()
{
	if (ButtonSound)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);

		UGameplayStatics::PlaySound2D(this, ButtonSound, BPC->GetSoundManager()->UIVolume, 1.0f);
	}
}

void UWC_BaseUserWidget::BackButtonSoundInit()
{
	if (BackButtonSound)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);

		UGameplayStatics::PlaySound2D(this, BackButtonSound, BPC->GetSoundManager()->UIVolume, 1.0f);
	}
}
