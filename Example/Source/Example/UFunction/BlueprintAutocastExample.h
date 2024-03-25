#pragma once

#include "BlueprintAutocastExample.generated.h"

UENUM(BlueprintType)
enum class EAnimal : uint8
{
	Cat,
	Dog,
	Walrus
};

UCLASS()
class UBlueprintAutocastExample : public UObject
{
	GENERATED_BODY()

public:
	// Note function must fulfill:
	// - Public
	// - Static
	// - BlueprintPure
	// - Return type
	UFUNCTION(BlueprintPure)
	static int32 AutocastAnimalToInteger(EAnimal Animal) { return 0; }
};
