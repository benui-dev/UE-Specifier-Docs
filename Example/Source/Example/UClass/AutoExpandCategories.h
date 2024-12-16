#pragma once

#include "UObject/Object.h"
#include "GameFramework/Actor.h"
#include "AutoExpandCategories.generated.h"

UCLASS(meta=(AutoExpandCategories="Example"), Blueprintable)
class UAutoExpandCategoriesExample : public UObject
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

USTRUCT()
struct FExampleStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Colors")
	FColor Color;

	UPROPERTY(EditAnywhere, Category="Beans")
	FColor Beans;
};

UCLASS(AutoExpandCategories="World Partition", AutoCollapseCategories="Replication,Rendering")
class AAutoExpandCategoriesActorExample : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Some Struct")
	FExampleStruct ExampleStruct;
	
	UPROPERTY(EditAnywhere, Category="Hello Struct")
	FExampleStruct AnotherStruct;

	UPROPERTY(EditAnywhere, Category="Not Example")
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere, Category="Not Example")
	FString SomeText = "Hello World!";
	
	UPROPERTY(EditAnywhere, Category="Example")
	FString TextWithinExample = "Hello World!";
};

UCLASS(meta=(AutoExpandCategories="World Partition", AutoCollapseCategories="Replication,Rendering"))
class AAutoExpandCategoriesMetadataActorExample : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Some Struct")
	FExampleStruct ExampleStruct;
	
	UPROPERTY(EditAnywhere, Category="Hello Struct")
	FExampleStruct AnotherStruct;

	UPROPERTY(EditAnywhere, Category="Not Example")
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere, Category="Not Example")
	FString SomeText = "Hello World!";
	
	UPROPERTY(EditAnywhere, Category="Example")
	FString TextWithinExample = "Hello World!";
};

/** Doesn't work */
UCLASS(meta=(AutoExpandCategories="World Partition", AutoCollapseCategories="Replication,Rendering"))
class AExampleA : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example")
	FString TextWithinExample = "Hello World!";
};

UCLASS(AutoExpandCategories=(Example,Cooking), AutoCollapseCategories=(Rendering,Collision))
class AExampleB : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example")
	FString TextWithinExample = "Hello World!";
};

UCLASS(AutoExpandCategories="Example", AutoCollapseCategories=(Rendering))
class AExampleC : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example")
	FString TextWithinExample = "Hello World!";
};

UCLASS(AutoExpandCategories=(ChildActorComponent), HideCategories=(Rendering,Replication,Collision,HLOD,Physics,Networking,Input,Actor,Cooking,LevelInstance,Streaming,DataLayers))
class AExampleD : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example")
	UChildActorComponent* ChildActorComponent;
};

UCLASS(AutoExpandCategories=(ExampleComponent), HideCategories=(Rendering,Replication,Collision,HLOD,Physics,Networking,Input,Actor,Cooking,LevelInstance,Streaming,DataLayers))
class AExampleE : public AActor
{
public:
	GENERATED_BODY()

	AExampleE();

	UPROPERTY(EditAnywhere, Category="Example")
	UExampleComponent* ExampleComponent;
};


UCLASS()
class UExampleComponent : public UActorComponent
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example Component Here")
	FColor Color;
};

UCLASS(CollapseCategories)
class AExampleF : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example")
	UExampleComponent* ExampleComponent;
};

UCLASS(meta=(PrioritizeCategories="Cooking"))
class AExampleG : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example")
	UExampleComponent* ExampleComponent;
};

UCLASS(AutoExpandCategories="Example Cooking")
class AExampleH : public AActor
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Example")
	FString TextWithinExample = "Hello World!";
};

UCLASS(EditInlineNew, BlueprintType)
class UExampleInlineA : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Things")
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere, Category="Stuff")
	FString SomeText = "Hello World!";
	UPROPERTY(EditAnywhere, Category="Stuff")
	FColor SomeColor;
};

UCLASS(Blueprintable, AutoExpandCategories=(Things), AutoCollapseCategories=(Stuff))
class UExampleInlineOuterA : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UExampleInlineA> EditInlineNewExample;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UExampleInlineA*> EditInlineNewExampleArray;
};

UCLASS(EditInlineNew, BlueprintType, AutoExpandCategories=(Things))
class UExampleInlineB : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Things")
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere, Category="Stuff")
	FString SomeText = "Hello World!";
	UPROPERTY(EditAnywhere, Category="Stuff")
	FColor SomeColor;
};

UCLASS(Blueprintable)
class UExampleInlineOuterB : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UExampleInlineB> EditInlineNewExample;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UExampleInlineB*> EditInlineNewExampleArray;
};

UCLASS(EditInlineNew, BlueprintType)
class UExampleInlineC : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Things")
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere, Category="Stuff")
	FString SomeText = "Hello World!";
	UPROPERTY(EditAnywhere, Category="Stuff")
	FColor SomeColor;
};

UCLASS(Blueprintable, AutoExpandCategories=(SomeNumber))
class UExampleInlineOuterC : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UExampleInlineC> EditInlineNewExample;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UExampleInlineC*> EditInlineNewExampleArray;
};

UCLASS(Blueprintable, AutoExpandCategories=(EditInlineNewExample))
class UExampleInlineOuterD : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UExampleInlineC> EditInlineNewExample;
	
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UExampleInlineC*> EditInlineNewExampleArray;
};
