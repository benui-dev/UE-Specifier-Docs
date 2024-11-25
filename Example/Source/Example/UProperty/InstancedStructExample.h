#pragma once

#include "UObject/Object.h"
#include "InstancedStruct.h"
#include "InstancedStructExample.generated.h"

USTRUCT(BlueprintType)
struct FBaseStruct
{
	GENERATED_BODY()
};

USTRUCT()
struct FDerivedStruct : public FBaseStruct
{
	GENERATED_BODY()
};

UCLASS(Blueprintable)
class UInstancedStructExample : public UObject
{
	GENERATED_BODY()

	// There are two different ways of limiting selection of instanced structs:

	// a) Specify type using meta BaseStruct specifier
	UPROPERTY(EditAnywhere, meta=(BaseStruct="/Script/Example.BaseStruct"))
	FInstancedStruct MetaBaseAndDerived;

	UPROPERTY(EditAnywhere, meta=(BaseStruct="/Script/Example.BaseStruct", ExcludeBaseStruct))
	FInstancedStruct MetaDerivedOnly;

	// b) Specify type using Templated TInstancedStruct<T>
	UPROPERTY(EditAnywhere)
	TInstancedStruct<FBaseStruct> TemplatedBaseAndDerived;

	UPROPERTY(EditAnywhere, meta=(ExcludeBaseStruct))
	TInstancedStruct<FBaseStruct> TemplatedDerivedOnly;
};
