// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/C_WorldHUD.h"
#include "Widget/WC_AttackOperationWidget.h"
#include "Widget/WC_PlayingWidget.h"
#include "Widget/WC_MapWidget.h"
#include "Widget/WC_ResultWidget.h"
#include "Widget/WC_PauseWidget.h"
#include "Widget/WC_InstructionWidget.h"
#include "MediaSoundComponent.h"

AC_WorldHUD::AC_WorldHUD()
{

}

void AC_WorldHUD::BeginPlay()
{
	Super::BeginPlay();

	SetPlayingWidgetVisible(true);

	MediaSound = NewObject<UMediaSoundComponent>(this);
	MediaSound->RegisterComponent();
	MediaSound->Activate(true);
}

void AC_WorldHUD::SetAttackOperationWidgetVisible(bool bOnShow)
{
	if (bOnShow)
	{
		if (!AttackOperationWidget || !AttackOperationWidget->IsInViewport())
		{
			if (AttackOperationWidgetClass)
			{
				AttackOperationWidget = Cast<UWC_AttackOperationWidget>(CreateWidget<UUserWidget>(GetOwningPlayerController(), AttackOperationWidgetClass));
			}
			if (AttackOperationWidget)
			{
				AttackOperationWidget->AddToViewport();
				AttackOperationWidget->SetVisibility(ESlateVisibility::Visible);
			}
			SetInputMode(EInputMode::UIOnly, true);
		}
	}
	else
	{
		if (AttackOperationWidget)
		{
			AttackOperationWidget->RemoveFromViewport();
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
}

void AC_WorldHUD::SetPlayingWidgetVisible(bool bOnShow)
{
	if (bOnShow)
	{
		if (!PlayingWidget || !PlayingWidget->IsInViewport())
		{
			if (PlayingWidgetClass)
			{
				PlayingWidget = Cast<UWC_PlayingWidget>(CreateWidget<UUserWidget>(GetOwningPlayerController(), PlayingWidgetClass));
			}
			if (PlayingWidget)
			{
				PlayingWidget->AddToViewport();
				PlayingWidget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			}
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
	else
	{
		if (PlayingWidget)
		{
			PlayingWidget->RemoveFromViewport();
			SetInputMode(EInputMode::UIOnly, true);
		}
	}
}

void AC_WorldHUD::SetMapWidgetVisible(bool bOnShow)
{
	if (bOnShow)
	{
		if (!MapWidget || !MapWidget->IsInViewport())
		{
			if (MapWidgetClass)
			{
				MapWidget = Cast<UWC_MapWidget>(CreateWidget<UUserWidget>(GetOwningPlayerController(), MapWidgetClass));
			}
			if (MapWidget)
			{
				MapWidget->AddToViewport();
				MapWidget->SetVisibility(ESlateVisibility::Visible);
			}
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
	else
	{
		if (MapWidget)
		{
			MapWidget->RemoveFromViewport();
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
}

void AC_WorldHUD::SetPauseWidgetVisible(bool bOnShow)
{
	if (bOnShow)
	{
		if (!PauseWidget || !PauseWidget->IsInViewport())
		{
			if (PauseWidgetClass)
			{
				PauseWidget = Cast<UWC_PauseWidget>(CreateWidget<UUserWidget>(GetOwningPlayerController(), PauseWidgetClass));
			}
			if (PauseWidget)
			{
				PauseWidget->AddToViewport();
				PauseWidget->SetVisibility(ESlateVisibility::Visible);
			}
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
	else
	{
		if (PauseWidget)
		{
			PauseWidget->RemoveFromViewport();
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
}

void AC_WorldHUD::SetResultWidgetVisible(bool bOnShow, int32 _Result)
{
	if (bOnShow)
	{
		if (!ResultWidget || !ResultWidget->IsInViewport())
		{
			if (ResultWidgetClass)
			{
				ResultWidget = Cast<UWC_ResultWidget>(CreateWidget<UUserWidget>(GetOwningPlayerController(), ResultWidgetClass));
			}
			if (ResultWidget)
			{
				ResultWidget->AddToViewport();
				ResultWidget->SetVisibility(ESlateVisibility::Visible);
				ResultWidget->WinResult(_Result);
			}
			SetInputMode(EInputMode::UIOnly, false);
		}
	}
	else
	{
		if (ResultWidget)
		{
			ResultWidget->RemoveFromViewport();
			SetInputMode(EInputMode::UIOnly, true);
		}
	}
}

void AC_WorldHUD::SetResultWidgetPlayerLose()
{
	if (!ResultWidget)return;

	ResultWidget->PlayerLose();
}

void AC_WorldHUD::SetResultWidgetAllOccupy()
{
	if (!ResultWidget)return;

	ResultWidget->AllOccupyWin();
}

void AC_WorldHUD::SetInstructionWidgetVisible(bool bOnShow)
{
	if (bOnShow)
	{
		if (!InstructionWidget || !InstructionWidget->IsInViewport())
		{
			if (InstructionWidgetClass)
			{
				InstructionWidget = Cast<UWC_InstructionWidget>(CreateWidget<UUserWidget>(GetOwningPlayerController(), InstructionWidgetClass));
			}
			if (InstructionWidget)
			{
				InstructionWidget->AddToViewport();
				InstructionWidget->SetVisibility(ESlateVisibility::Visible);
			}
			SetInputMode(EInputMode::UIOnly, true);
		}
	}
	else
	{
		if (InstructionWidget)
		{
			InstructionWidget->RemoveFromViewport();
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
}

void AC_WorldHUD::SetInstructionCloseButton()
{
	if (!InstructionWidget)return;

	InstructionWidget->SetCloseButton();
}
