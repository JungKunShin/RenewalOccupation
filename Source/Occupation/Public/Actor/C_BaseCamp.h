// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/C_BaseStructure.h"
#include "C_BaseCamp.generated.h"

/**
 * 
 */
UCLASS()
class OCCUPATION_API AC_BaseCamp : public AC_BaseStructure
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay()override;
};
