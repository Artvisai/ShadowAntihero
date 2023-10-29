// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SASaveGame.generated.h"

/**
 *
 */
UCLASS()
class SHADOWANTIHERO_API USASaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Player Info")
	FVector PlayerLocation;
};
