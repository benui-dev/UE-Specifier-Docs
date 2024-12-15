#pragma once

#include "UObject/Object.h"
#include "AutoExpandCategories.generated.h"

UCLASS(AutoExpandCategories="Example", Blueprintable)
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
