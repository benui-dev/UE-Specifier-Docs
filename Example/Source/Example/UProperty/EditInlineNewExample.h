#pragma once

#include "UObject/Object.h"
#include "EditInlineNewExample.generated.h"

UCLASS(EditInlineNew)
class UThingy : public UObject
{
	GENERATED_BODY()
public:
	
};


UCLASS(Blueprintable)
class UEditInlineNewExample : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UThingy> SingleThingy;
	
	UPROPERTY(EditAnywhere)
	TArray<UThingy*> Thingies;
};

