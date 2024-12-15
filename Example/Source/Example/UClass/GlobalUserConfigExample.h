#pragma once

#include "UObject/Object.h"
#include "GlobalUserConfigExample.generated.h"

UCLASS(config=Engine, GlobalUserConfig, Blueprintable)
class UGlobalUserConfigExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(GlobalConfig, EditAnywhere)
	int32 GlobalConfig = 1;
};
