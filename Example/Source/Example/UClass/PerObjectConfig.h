#pragma once

#include "UObject/Object.h"
#include "GameFramework/Actor.h"
#include "PerObjectConfig.generated.h"

UCLASS(config=Engine, PerObjectConfig, Blueprintable)
class UPerObjectConfigObjectExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere)
	int32 ExampleInt= 1;
};

UCLASS(config=Engine, PerObjectConfig, Blueprintable)
class APerObjectConfigActorExample : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere)
	int32 ExampleInt= 1;
};
