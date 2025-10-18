// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WC_BaseUserWidget.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "WC_DisplayWidget.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API UWC_DisplayWidget : public UWC_BaseUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	// ---- Handlers ----
	UFUNCTION()
	void OnWindowModeChanged(FString Selected, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnResolutionChanged(FString Selected, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnBrightnessChanged(float Normalized);

	// ---- Helpers ----
	void LoadInitialSettingsToUI();
	void ApplyWindowModeAndResolution();
	void ApplyBrightnessLevel(int32 Level01to10);

	static FIntPoint ParseRes(const FString& In);
	static FString  ToResString(const FIntPoint& In);

	static float BrightnessToGamma(int32 Level01to10);
	static int32 GammaToBrightness(float Gamma);

	void SaveBrightnessToConfig(float Gamma);
	float LoadBrightnessFromConfig() const;

private:

	UPROPERTY(meta = (BindWidget))
	UComboBoxString* Combo_WindowMode;

	UPROPERTY(meta = (BindWidget))
	UComboBoxString* Combo_Resolution;

	UPROPERTY(meta = (BindWidget))
	USlider* Slider_Brightness;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Text_BrightnessValue;


};
