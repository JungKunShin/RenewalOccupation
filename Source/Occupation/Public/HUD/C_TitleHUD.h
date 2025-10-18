// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/C_BaseHUD.h"
#include "C_TitleHUD.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API AC_TitleHUD : public AC_BaseHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay()override;
	
public:
	void SetTitleWidgetVisible(bool bOnShow);

public:
	UPROPERTY(BlueprintReadWrite)
	class UWC_TitleWidget* TitleWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> TitleWidgetClass;
};
