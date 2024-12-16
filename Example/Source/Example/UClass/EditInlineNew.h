#pragma once

#include "UObject/Object.h"
#include "EditInlineNew.generated.h"

UCLASS(EditInlineNew, BlueprintType)
class UEditInlineNewExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere)
	FString SomeText = "Hello World!";
};

UCLASS(Blueprintable)
class UEditInlineNewOuterExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UEditInlineNewExample> EditInlineNewExample;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UEditInlineNewExample*> EditInlineNewExampleArray;
};
