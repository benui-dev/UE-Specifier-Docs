#pragma once

#include "UObject/Object.h"
#include "AutoCollapseCategories.generated.h"

UCLASS(AutoCollapseCategories="Example", Blueprintable)
class UAutoCollapseCategoriesExample : public UObject
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
