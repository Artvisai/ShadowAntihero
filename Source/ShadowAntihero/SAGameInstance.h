// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SASaveGame.h"
#include "Engine/GameInstance.h"
#include "SAGameInstance.generated.h"

/**
 *
 */
UCLASS()
class SHADOWANTIHERO_API USAGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	USAGameInstance();

	// Optional this will be the save file name. Initialization is in constructor.
	UPROPERTY(BlueprintReadOnly)
	FString SaveGameSlotName;

	UPROPERTY(BlueprintReadWrite, Category = "Settings")
	USASaveGame* SaveGameObject;

	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void LoadGame();

	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void SaveGame();

private:
	void LogIfGameWasSavedOrNot(const bool IsSaved);
};
