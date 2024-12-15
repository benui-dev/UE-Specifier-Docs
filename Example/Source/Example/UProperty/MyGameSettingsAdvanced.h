#pragma once

#include "Engine/DeveloperSettings.h"
#include "MyGameSettingsAdvanced.generated.h"

UCLASS(config=Game, DefaultConfig)
class UMyGameSettingsAdvanced : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	//~ Begin UDeveloperSettings interface
	virtual FName GetCategoryName() const;
#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
#endif
	//~ End UDeveloperSettings interface
	
protected:
	UPROPERTY(Config, EditAnywhere, Category="Dog-related Settings")
	int32 DogCount = 0;
	
	UPROPERTY(Config, EditAnywhere, Category="Dog-related Settings")
	FName DefaultDogId = "Bingo";
};