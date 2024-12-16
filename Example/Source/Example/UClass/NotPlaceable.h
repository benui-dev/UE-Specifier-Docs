#pragma once

#include "GameFramework/Actor.h"
#include "NotPlaceable.generated.h"

UCLASS(NotPlaceable, Blueprintable)
class ANotPlaceableExample : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SomeNumber = 1;
};
