// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_VolumeWidget.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerController/C_BasePlayerController.h"
#include "Manager/C_SoundManager.h"
#include "Components/TextBlock.h"

void UWC_VolumeWidget::NativeConstruct()
{
    Super::NativeConstruct();

    AudioVolumeSlider_Master->OnValueChanged.AddDynamic(this, &UWC_VolumeWidget::OnMasterVolumeChanged);
    AudioVolumeSlider_BackGround->OnValueChanged.AddDynamic(this, &UWC_VolumeWidget::OnBGMVolumeChanged);
    AudioVolumeSlider_Effect->OnValueChanged.AddDynamic(this, &UWC_VolumeWidget::OnEffectVolumeChanged);
    AudioVolumeSlider_UI->OnValueChanged.AddDynamic(this, &UWC_VolumeWidget::OnUIVolumeChanged);

    GetWorld()->GetTimerManager().ClearTimer(SoundInitTH);
    GetWorld()->GetTimerManager().SetTimer(SoundInitTH, this, &UWC_VolumeWidget::InitVolumeSound, 0.3f, false);
    /*InitVolumeSound();*/
}

void UWC_VolumeWidget::OnMasterVolumeChanged(float NewValue)
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);
    BPC->GetSoundManager()->SetAllMasterVolume(NewValue);

    TEXT_Master->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->MasterVolume * 100.f)));
}

void UWC_VolumeWidget::OnBGMVolumeChanged(float NewValue)
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);
    BPC->GetSoundManager()->SetBGMVolume(NewValue);

    TEXT_BGM->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->BGMVolume * 100.f)));
}

void UWC_VolumeWidget::OnEffectVolumeChanged(float NewValue)
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);
    BPC->GetSoundManager()->SetEffectVolume(NewValue);

    TEXT_Effect->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->EffectVolume * 100.f)));
}

void UWC_VolumeWidget::OnUIVolumeChanged(float NewValue)
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);
    BPC->GetSoundManager()->SetUIVolume(NewValue);

    TEXT_UI->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->OriginalUIVolume * 100.f)));
}

void UWC_VolumeWidget::InitVolumeSound()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    AC_BasePlayerController* BPC = Cast< AC_BasePlayerController>(PC);

    AudioVolumeSlider_Master->SetValue(BPC->GetSoundManager()->MasterVolume);
    AudioVolumeSlider_BackGround->SetValue(BPC->GetSoundManager()->BGMVolume);
    AudioVolumeSlider_Effect->SetValue(BPC->GetSoundManager()->EffectVolume);
    AudioVolumeSlider_UI->SetValue(BPC->GetSoundManager()->OriginalUIVolume);

    TEXT_Master->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->MasterVolume * 100.f)));
    TEXT_BGM->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->BGMVolume * 100.f)));
    TEXT_Effect->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->EffectVolume * 100.f)));
    TEXT_UI->SetText(FText::AsNumber(FMath::RoundToInt(BPC->GetSoundManager()->OriginalUIVolume * 100.f)));
    GetWorld()->GetTimerManager().ClearTimer(SoundInitTH);
}
