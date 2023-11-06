// Fill out your copyright notice in the Description page of Project Settings.


#include "SAGameInstance.h"
#include "Kismet/GameplayStatics.h"

USAGameInstance::USAGameInstance()
{
    SaveGameSlotName = "SaveGameExample";
}

void USAGameInstance::LoadGame()
{
    // Try to load a saved game file (with name: <SaveGameSlotName>.sav) if exists
    USaveGame* LoadedGame = UGameplayStatics::LoadGameFromSlot(SaveGameSlotName, 0);
    SaveGameObject = Cast<USASaveGame>(LoadedGame);

    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Trying to load a saved game."));

    // If file does not exist try create a new one
    if (!SaveGameObject)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("No saved games found. Trying to save a new one."));

        // Instantiate a new SaveGame object
        SaveGameObject = Cast<USASaveGame>(UGameplayStatics::CreateSaveGameObject(USASaveGame::StaticClass()));

        // Call SaveGameToSlot to serialize and save our SaveGameObject with name: <SaveGameSlotName>.sav
        const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveGameSlotName, 0);

        LogIfGameWasSavedOrNot(IsSaved);
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saved game found. Loaded."));
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, SaveGameSlotName);
    }

}

void USAGameInstance::SaveGame()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saving game..."));

    // Call SaveGameToSlot to serialize and save our SaveGameObject with name: <SaveGameSlotName>.sav
    const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveGameSlotName, 0);

    LogIfGameWasSavedOrNot(IsSaved);

}

void USAGameInstance::LogIfGameWasSavedOrNot(const bool IsSaved)
{
    if (IsSaved)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Game saved."));
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Cannot save the game."));
    }
}