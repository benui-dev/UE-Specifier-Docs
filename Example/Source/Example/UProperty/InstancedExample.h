#pragma once

#include "UObject/Object.h"
#include "InstancedExample.generated.h"

UCLASS()
class UInstancedInner : public UObject
{
	GENERATED_BODY()
public:
	
};


UCLASS(Blueprintable)
class UInstancedExample : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UInstancedInner> SingleInstancedInner;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UInstancedInner*> InstancedInners;
};
