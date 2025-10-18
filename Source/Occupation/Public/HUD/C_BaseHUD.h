// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "C_BaseHUD.generated.h"

/**
 * 
 */
UENUM()
enum class EInputMode : uint8 //ÀÎÇ² ¸ðµå
{
	UIOnly UMETA(DisplayName = "UIOnly"),

	GameAndUI    UMETA(DisplayName = "GameAndUI"),

	GameOnly  UMETA(DisplayName = "GameOnly")
};

UCLASS()
class OCCUPATION_API AC_BaseHUD : public AHUD
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:
	void SetInputMode(EInputMode InputMode, bool ShowMouseCurSor);
	
};
