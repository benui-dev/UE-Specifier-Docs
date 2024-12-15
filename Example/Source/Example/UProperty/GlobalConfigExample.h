#pragma once

#include "GameFramework/Actor.h"
#include "GlobalConfigExample.generated.h"

UCLASS(config=Game)
class AGlobalConfigExampleParent : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(Config, EditAnywhere)
	int32 ConfigExample = 0;

	UPROPERTY(GlobalConfig, EditAnywhere)
	int32 GlobalConfigExample = 0;
};

UCLASS(config=Game)
class AGlobalConfigExampleChild : public AGlobalConfigExampleParent
{
	GENERATED_BODY()
};

UCLASS()
class AGlobalConfigExampleGrandChild : public AGlobalConfigExampleChild
{
	GENERATED_BODY()
};
