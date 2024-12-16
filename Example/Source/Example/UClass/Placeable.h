#pragma once

#include "GameFramework/Actor.h"
#include "Placeable.generated.h"

UCLASS(Placeable, Blueprintable)
class APlaceableExample : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SomeNumber = 1;
};

/** An actor with neither Placeable nor NonPlaceable */
UCLASS(Blueprintable)
class ANoPlaceableSpecifierExample : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SomeNumber = 1;
};
