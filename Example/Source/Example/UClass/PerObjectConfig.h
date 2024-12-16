#pragma once

#include "UObject/Object.h"
#include "Engine/DeveloperSettings.h"
#include "PerObjectConfig.generated.h"

UCLASS(config=Game, PerObjectConfig, DefaultToInstanced)
class UPerObjectConfigExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere)
	int32 ExampleInt = 1;

	UPROPERTY(Config, EditAnywhere)
	FString ExampleString = "Hello world!";
};

UCLASS(config=Game, PerObjectConfig, EditInlineNew)
class UPerObjectConfigEditInlineNewExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere)
	int32 ExampleInt = 1;

	UPROPERTY(Config, EditAnywhere)
	FString ExampleString = "Hello world!";
};

UCLASS(config=Game, Category="PerObjectSettings")
class UPerObjectSettingsExample : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPerObjectSettingsExample(const FObjectInitializer& ObjectInitializer)
		: Super(ObjectInitializer)
	{
		// Large text for where settings should be grouped on the left
		CategoryName = "Project";
		// Smaller sub-heading for grouping
		SectionName = "Per Object Config";
	}
	
	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UPerObjectConfigExample> PerObjectConfig;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UPerObjectConfigEditInlineNewExample> EditInlineNewExample;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UPerObjectConfigExample*> PerObjectConfigArray;
};