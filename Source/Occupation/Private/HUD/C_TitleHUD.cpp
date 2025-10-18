// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/C_TitleHUD.h"
#include "Widget/WC_TitleWidget.h"

void AC_TitleHUD::BeginPlay()
{
	Super::BeginPlay();
	SetTitleWidgetVisible(true);
}

void AC_TitleHUD::SetTitleWidgetVisible(bool bOnShow)
{
	if (bOnShow)
	{
		if (!TitleWidget || !TitleWidget->IsInViewport())
		{
			if (TitleWidgetClass)
			{
				TitleWidget = Cast<UWC_TitleWidget>(CreateWidget<UUserWidget>(GetOwningPlayerController(), TitleWidgetClass));
			}
			if (TitleWidget)
			{
				TitleWidget->AddToViewport();
				TitleWidget->SetVisibility(ESlateVisibility::Visible);
			}
			SetInputMode(EInputMode::UIOnly, true);
		}
	}
	else
	{
		if (TitleWidget)
		{
			TitleWidget->RemoveFromViewport();
			SetInputMode(EInputMode::GameAndUI, true);
		}
	}
}
