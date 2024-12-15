#pragma once

#include "UObject/Object.h"
#include "GameFramework/Actor.h"
#include "ConfigDoNotCheckDefaults.generated.h"

UCLASS(config=Engine, ConfigDoNotCheckDefaults)
class UConfigDoNotCheckDefaultsExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere)
	int32 ExampleInt = 1;

	UPROPERTY(Config, EditAnywhere)
	FString ExampleString = "Hello world!";
};
