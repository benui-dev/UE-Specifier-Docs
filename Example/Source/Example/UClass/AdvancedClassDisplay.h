#pragma once

#include "UObject/Object.h"
#include "AdvancedClassDisplay.generated.h"

UCLASS(AdvancedClassDisplay, Blueprintable)
class UAdvancedClassDisplayExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere)
	FString SomeText = "Hello World!";
};
