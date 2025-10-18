// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_AttackOperationWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "PlayerController/C_WorldPlayerController.h"
#include "HUD/C_WorldHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameState/C_WorldGameState.h"
#include "Actor/C_BaseStructure.h"

void UWC_AttackOperationWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	Text_CanTroops->SetText(FText::AsNumber(WGS->GetStructure()->TroopInfo.PlayerTroops));

	BCRButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnBCRButtonClicked);
	BCBButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnBCBButtonClicked);
	BCGButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnBCGButtonClicked);
	T1AButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT1AButtonClicked);
	T1BButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT1BButtonClicked);
	T1CButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT1CButtonClicked);
	T2AButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT2AButtonClicked);
	T2BButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT2BButtonClicked);
	T2CButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT2CButtonClicked);
	T3AButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT3AButtonClicked);
	T3BButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT3BButtonClicked);
	T3CButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT3CButtonClicked);
	T4AButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT4AButtonClicked);
	T4BButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT4BButtonClicked);
	T4CButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT4CButtonClicked);
	T5AButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT5AButtonClicked);
	T5BButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT5BButtonClicked);
	T5CButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnT5CButtonClicked);
	CenterButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnCenterButtonClicked);
	FirstBackButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnWidgetBackButtonClicked);
	SecondBackButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnWidgetBackButtonClicked);
	TroopUpButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnTroopUpButtonClicked);
	TroopDownButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnTroopDownButtonClicked);
	TroopTenUpButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnTroopTenUpButtonClicked);
	TroopTenDownButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnTroopTenDownButtonClicked);
	MoveButton->OnClicked.AddDynamic(this, &UWC_AttackOperationWidget::OnMoveButtonClicked);

	MoveButton->SetVisibility(ESlateVisibility::Hidden);
	MoveButtonBorder->SetVisibility(ESlateVisibility::Hidden);
}

void UWC_AttackOperationWidget::OnBCRButtonClicked()
{
	WidgetButtonSoundInit();

	TagName = TEXT("BCR");

	CloselyJudgement();
}

void UWC_AttackOperationWidget::OnBCBButtonClicked()
{
	WidgetButtonSoundInit();

	TagName = TEXT("BCB");

	CloselyJudgement();
}

void UWC_AttackOperationWidget::OnBCGButtonClicked()
{
	TagName = TEXT("BCG");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT1AButtonClicked()
{
	TagName = TEXT("T1A");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT1BButtonClicked()
{
	TagName = TEXT("T1B");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT1CButtonClicked()
{
	TagName = TEXT("T1C");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT2AButtonClicked()
{
	TagName = TEXT("T2A");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT2BButtonClicked()
{
	TagName = TEXT("T2B");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT2CButtonClicked()
{
	TagName = TEXT("T2C");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT3AButtonClicked()
{
	TagName = TEXT("T3A");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT3BButtonClicked()
{
	TagName = TEXT("T3B");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT3CButtonClicked()
{
	TagName = TEXT("T3C");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT4AButtonClicked()
{
	TagName = TEXT("T4A");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT4BButtonClicked()
{
	TagName = TEXT("T4B");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT4CButtonClicked()
{
	TagName = TEXT("T4C");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT5AButtonClicked()
{
	TagName = TEXT("T5A");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT5BButtonClicked()
{
	TagName = TEXT("T5B");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnT5CButtonClicked()
{
	TagName = TEXT("T5C");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnCenterButtonClicked()
{
	TagName = TEXT("Center");

	CloselyJudgement();
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnWidgetBackButtonClicked()
{
	if (AttackWidgetSwitcher->GetActiveWidgetIndex() == 0)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		AC_WorldPlayerController* WPC = Cast<AC_WorldPlayerController>(PC);
		if (!WPC)return;
		AC_WorldHUD* WH = Cast< AC_WorldHUD>(WPC->GetHUD());
		if (!WH)return;

		WH->SetAttackOperationWidgetVisible(false);
	}
	else
	{
		AttackWidgetSwitcher->SetActiveWidgetIndex(0);
	}
	BackButtonSoundInit();
}

void UWC_AttackOperationWidget::OnMoveButtonClicked()
{
	AttackWidgetSwitcher->SetActiveWidgetIndex(1);
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnTroopUpButtonClicked()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (WGS->GetStructure()->TroopInfo.PlayerTroops > CurTroops)
	{
		++CurTroops;
		Text_CurTroops->SetText(FText::AsNumber(CurTroops));
		if (CurTroops)
		{
			MoveButton->SetVisibility(ESlateVisibility::Visible);
			MoveButtonBorder->SetVisibility(ESlateVisibility::Visible);
		}
	}
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnTroopTenUpButtonClicked()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (WGS->GetStructure()->TroopInfo.PlayerTroops >= CurTroops+10)
	{
		CurTroops+=10;
		Text_CurTroops->SetText(FText::AsNumber(CurTroops));
		if (CurTroops)
		{
			MoveButton->SetVisibility(ESlateVisibility::Visible);
			MoveButtonBorder->SetVisibility(ESlateVisibility::Visible);
		}
	}
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnTroopDownButtonClicked()
{
	if (CurTroops>0)
	{
		--CurTroops;
		Text_CurTroops->SetText(FText::AsNumber(CurTroops));
		if (!CurTroops)
		{
			MoveButton->SetVisibility(ESlateVisibility::Hidden);
			MoveButtonBorder->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::OnTroopTenDownButtonClicked()
{
	if (CurTroops >=10)
	{
		CurTroops-=10;
		Text_CurTroops->SetText(FText::AsNumber(CurTroops));
		if (!CurTroops)
		{
			MoveButton->SetVisibility(ESlateVisibility::Hidden);
			MoveButtonBorder->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	WidgetButtonSoundInit();
}

void UWC_AttackOperationWidget::InitButtonColor()
{
}

void UWC_AttackOperationWidget::CloselyJudgement()
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	TArray<AActor*> SurroundingLoc = WGS->GetStructure()->Surroundings;

	for (AActor* MyActor : SurroundingLoc)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			if (CurStructure->Tags[0] == TagName)
			{
				CurStructure->TroopInfo.PlayerTroops += CurTroops;
				WGS->GetStructure()->TroopInfo.PlayerTroops -= CurTroops;

				APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
				AC_WorldPlayerController* WPC = Cast<AC_WorldPlayerController>(PC);
				if (!WPC)return;
				AC_WorldHUD* WH = Cast< AC_WorldHUD>(WPC->GetHUD());
				if (!WH)return;

				WH->SetAttackOperationWidgetVisible(false);
				break;
			}
		}
	}
}
