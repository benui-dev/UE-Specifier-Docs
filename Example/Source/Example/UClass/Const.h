#pragma once

#include "UObject/Object.h"
#include "Const.generated.h"

UCLASS(Const, Blueprintable)
class UConstExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Not Example")
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere, Category="Not Example")
	FString SomeText = "Hello World!";
	
	UPROPERTY(EditAnywhere, Category="Example")
	FString TextWithinExample = "Hello World!";
};
