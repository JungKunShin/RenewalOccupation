// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/WC_MapWidget.h"
#include "Actor/C_BaseStructure.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "GameState/C_WorldGameState.h"

void UWC_MapWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BCRInit();
	BCBInit();
	BCGInit();
	T1AInit();
	T1BInit();
	T1CInit();
	T2AInit();
	T2BInit();
	T2CInit();
	T3AInit();
	T3BInit();
	T3CInit();
	T4AInit();
	T4BInit();
	T4CInit();
	T5AInit();
	T5BInit();
	T5CInit();
	CenterInit();
}

void UWC_MapWidget::InitColor(UImage* _Image, EWho _Who)
{
	AC_WorldGameState* WGS = GetWorld()->GetGameState< AC_WorldGameState>();
	if (!WGS)return;

	EGameTribe WinTribe;
	
	switch (_Who)
	{
	case EWho::Player:
		WinTribe = WGS->Tribes[0];
		break;
	case EWho::AIOne:
		WinTribe = WGS->Tribes[1];
		break;
	case EWho::AITwo:
		WinTribe = WGS->Tribes[2];
		break;
	case EWho::None:
	default:
		_Image->SetColorAndOpacity(FLinearColor::White);
		return;
	}

	switch (WinTribe)
	{
	case EGameTribe::Korea:
		_Image->SetColorAndOpacity(FLinearColor::Blue);
		break;
	case EGameTribe::China:
		_Image->SetColorAndOpacity(FLinearColor::Red);
		break;
	case EGameTribe::Egypt:
		_Image->SetColorAndOpacity(FLinearColor::Yellow);
		break;
	default:
		break;
	}
}

void UWC_MapWidget::InitText(UTextBlock* _TextBlock, EWho _Who, FName _TagName,UTextBlock* _CanTextBlock)
{
	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), _TagName, StructureActor);
	AC_BaseStructure* ApplyStructure=nullptr;

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			ApplyStructure = CurStructure;
			break;
		}
	}

	if (!ApplyStructure)return;

	switch (_Who)
	{
	case EWho::Player:
		_TextBlock->SetText(FText::AsNumber(ApplyStructure->TroopInfo.PrePTroops));
		break;
	case EWho::AIOne:
		_TextBlock->SetText(FText::AsNumber(ApplyStructure->TroopInfo.PreAI1Troops));
		break;
	case EWho::AITwo:
		_TextBlock->SetText(FText::AsNumber(ApplyStructure->TroopInfo.PreAI2Troops));
		break;
	case EWho::None:
	default:
		_TextBlock->SetText(FText::AsNumber(0));
		break;
	}
	if (_Who==EWho::Player)
	{
		int32 Num = ApplyStructure->TroopInfo.PlayerTroops;
		FString TextString = FString::Printf(TEXT("(%d)"), Num);
		_CanTextBlock->SetText(FText::FromString(TextString));
	}
}

EWho UWC_MapWidget::WhoOwn(FName _TagName)
{
	TArray<AActor*> StructureActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), _TagName, StructureActor);

	for (AActor* MyActor : StructureActor)
	{
		AC_BaseStructure* CurStructure = Cast<AC_BaseStructure>(MyActor);
		if (CurStructure)
		{
			return CurStructure->TroopInfo.Who;
		}
	}
	return EWho::None;
}

void UWC_MapWidget::BCRInit()
{
	FName TagName = FName("BCR");
	InitColor(BCRColor, WhoOwn(TagName));
	InitText(Text_BCRTroop, WhoOwn(TagName),TagName, Text_CanBCRTroop);
}

void UWC_MapWidget::BCBInit()
{
	FName TagName = FName("BCB");
	InitColor(BCBColor, WhoOwn(TagName));
	InitText(Text_BCBTroop, WhoOwn(TagName), TagName, Text_CanBCBTroop);
}

void UWC_MapWidget::BCGInit()
{
	FName TagName = FName("BCG");
	InitColor(BCGColor, WhoOwn(TagName));
	InitText(Text_BCGTroop, WhoOwn(TagName), TagName, Text_CanBCGTroop);
}

void UWC_MapWidget::T1AInit()
{
	FName TagName = FName("T1A");
	InitColor(T1AColor, WhoOwn(TagName));
	InitText(Text_T1ATroop, WhoOwn(TagName), TagName, Text_CanT1ATroop);
}

void UWC_MapWidget::T1BInit()
{
	FName TagName = FName("T1B");
	InitColor(T1BColor, WhoOwn(TagName));
	InitText(Text_T1BTroop, WhoOwn(TagName), TagName, Text_CanT1BTroop);
}

void UWC_MapWidget::T1CInit()
{
	FName TagName = FName("T1C");
	InitColor(T1CColor, WhoOwn(TagName));
	InitText(Text_T1CTroop, WhoOwn(TagName), TagName, Text_CanT1CTroop);
}

void UWC_MapWidget::T2AInit()
{
	FName TagName = FName("T2A");
	InitColor(T2AColor, WhoOwn(TagName));
	InitText(Text_T2ATroop, WhoOwn(TagName), TagName, Text_CanT2ATroop);
}

void UWC_MapWidget::T2BInit()
{
	FName TagName = FName("T2B");
	InitColor(T2BColor, WhoOwn(TagName));
	InitText(Text_T2BTroop, WhoOwn(TagName), TagName, Text_CanT2BTroop);
}

void UWC_MapWidget::T2CInit()
{
	FName TagName = FName("T2C");
	InitColor(T2CColor, WhoOwn(TagName));
	InitText(Text_T2CTroop, WhoOwn(TagName), TagName, Text_CanT2CTroop);
}

void UWC_MapWidget::T3AInit()
{
	FName TagName = FName("T3A");
	InitColor(T3AColor, WhoOwn(TagName));
	InitText(Text_T3ATroop, WhoOwn(TagName), TagName, Text_CanT3ATroop);
}

void UWC_MapWidget::T3BInit()
{
	FName TagName = FName("T3B");
	InitColor(T3BColor, WhoOwn(TagName));
	InitText(Text_T3BTroop, WhoOwn(TagName), TagName, Text_CanT3BTroop);
}

void UWC_MapWidget::T3CInit()
{
	FName TagName = FName("T3C");
	InitColor(T3CColor, WhoOwn(TagName));
	InitText(Text_T3CTroop, WhoOwn(TagName), TagName, Text_CanT3CTroop);
}

void UWC_MapWidget::T4AInit()
{
	FName TagName = FName("T4A");
	InitColor(T4AColor, WhoOwn(TagName));
	InitText(Text_T4ATroop, WhoOwn(TagName), TagName, Text_CanT4ATroop);
}

void UWC_MapWidget::T4BInit()
{
	FName TagName = FName("T4B");
	InitColor(T4BColor, WhoOwn(TagName));
	InitText(Text_T4BTroop, WhoOwn(TagName), TagName, Text_CanT4BTroop);
}

void UWC_MapWidget::T4CInit()
{
	FName TagName = FName("T4C");
	InitColor(T4CColor, WhoOwn(TagName));
	InitText(Text_T4CTroop, WhoOwn(TagName), TagName, Text_CanT4CTroop);
}

void UWC_MapWidget::T5AInit()
{
	FName TagName = FName("T5A");
	InitColor(T5AColor, WhoOwn(TagName));
	InitText(Text_T5ATroop, WhoOwn(TagName), TagName, Text_CanT5ATroop);
}

void UWC_MapWidget::T5BInit()
{
	FName TagName = FName("T5B");
	InitColor(T5BColor, WhoOwn(TagName));
	InitText(Text_T5BTroop, WhoOwn(TagName), TagName, Text_CanT5BTroop);
}

void UWC_MapWidget::T5CInit()
{
	FName TagName = FName("T5C");
	InitColor(T5CColor, WhoOwn(TagName));
	InitText(Text_T5CTroop, WhoOwn(TagName), TagName, Text_CanT5CTroop);
}

void UWC_MapWidget::CenterInit()
{
	FName TagName = FName("Center");
	InitColor(CenterColor, WhoOwn(TagName));
	InitText(Text_CenterTroop, WhoOwn(TagName), TagName, Text_CanCenterTroop);
}
