// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameUserSettings.h"
#include "AirsimGameMode_Differential.generated.h"

/**
 * 
 */
UCLASS()
class AIRSIM_API AAirsimGameMode_Differential : public AGameModeBase
{
public:
	GENERATED_BODY()

    virtual void StartPlay() override;

    AAirsimGameMode_Differential(const FObjectInitializer& ObjectInitializer);

    //private:
    //UGameUserSettings* GetGameUserSettings();
};
