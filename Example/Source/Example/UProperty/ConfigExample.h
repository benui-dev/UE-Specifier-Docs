#pragma once

#include "Engine/DeveloperSettings.h"
#include "ConfigExample.generated.h"

UCLASS(config=Game)
class UGameConfigExample : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UGameConfigExample();
	
protected:
	UPROPERTY(Config, EditAnywhere)
	int32 ConfigExample = 0;

	UPROPERTY(GlobalConfig, EditAnywhere)
	int32 GlobalConfigExample = 0;

	UPROPERTY(EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyEditable = 0;

	UPROPERTY(Config, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithConfig = 0;
	
	UPROPERTY(GlobalConfig, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithGlobalConfig = 0;
};

UCLASS(config=Game, DefaultConfig)
class UGameDefaultConfigExample : public UDeveloperSettings
{
	GENERATED_BODY()
	UGameDefaultConfigExample(const FObjectInitializer& ObjectInitializer);

protected:
	UPROPERTY(Config, EditAnywhere)
	int32 ConfigExample = 0;

	UPROPERTY(GlobalConfig, EditAnywhere)
	int32 GlobalConfigExample = 0;

	UPROPERTY(EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyEditable = 0;

	UPROPERTY(Config, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithConfig = 0;
	
	UPROPERTY(GlobalConfig, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithGlobalConfig = 0;
};

UCLASS(config=BaconEgg, DefaultConfig)
class UBaconEggDefaultConfigExample : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UBaconEggDefaultConfigExample();
	
protected:
	UPROPERTY(Config, EditAnywhere)
	int32 ConfigExample = 0;

	UPROPERTY(GlobalConfig, EditAnywhere)
	int32 GlobalConfigExample = 0;

	UPROPERTY(EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyEditable = 0;

	UPROPERTY(Config, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithConfig = 0;
	
	UPROPERTY(GlobalConfig, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithGlobalConfig = 0;
};

UCLASS(config=Cheesecake)
class UCheesecakeConfigExample : public UDeveloperSettings
{
	GENERATED_BODY()

	UPROPERTY(Config)
	int32 CheesecakeConfigExample;

	UPROPERTY(GlobalConfig)
	int32 CheesecakeGlobalConfigExample;

	UPROPERTY(meta=(ConfigHierarchyEditable))
	int32 CheesecakeConfigHierarchyEditable;
};

UCLASS(config=Something, DefaultConfig)
class USomethingConfigExample : public UDeveloperSettings
{
	GENERATED_BODY()

	UPROPERTY(Config)
	int32 SomethingConfigExample = 54;
};

UCLASS(config=Game, DefaultConfig)
class UMyConfigExample : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UMyConfigExample() { CategoryName="My Config"; }
	
protected:
	UPROPERTY(Config, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithConfig = 0;
	
	UPROPERTY(GlobalConfig, EditAnywhere, meta=(ConfigHierarchyEditable))
	int32 ConfigHierarchyWithGlobalConfig = 0;
};
