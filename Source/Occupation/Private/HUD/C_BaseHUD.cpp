// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/C_BaseHUD.h"

void AC_BaseHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AC_BaseHUD::SetInputMode(EInputMode InputMode, bool ShowMouseCurSor)
{
	FInputModeUIOnly UIOnly;
	FInputModeGameAndUI GameAndUI;
	FInputModeGameOnly GameOnly;

	switch (InputMode)
	{
	case EInputMode::UIOnly:
		GetOwningPlayerController()->SetInputMode(UIOnly);
		break;
	case EInputMode::GameAndUI:
		GetOwningPlayerController()->SetInputMode(GameAndUI);
		break;
	case EInputMode::GameOnly:
		GetOwningPlayerController()->SetInputMode(GameOnly);
		break;
	default:
		break;
	}

	GetOwningPlayerController()->bShowMouseCursor = ShowMouseCurSor;
}
