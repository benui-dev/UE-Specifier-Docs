#pragma once

#include "Engine/DeveloperSettings.h"
#include "MyGameSettings.generated.h"

UCLASS(config=Game, DefaultConfig, Category="Blah Settings")
class UMyGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UMyGameSettings(const FObjectInitializer& ObjectInitializer);
	
protected:
	UPROPERTY(Config, EditAnywhere, Category="Dog-related Settings")
	int32 DogCount = 0;
	
	UPROPERTY(Config, EditAnywhere, Category="Dog-related Settings")
	FName DefaultDogId = "Bingo";
};