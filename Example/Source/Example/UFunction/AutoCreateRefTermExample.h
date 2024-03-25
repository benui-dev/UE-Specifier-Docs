#pragma once

#include "AutoCreateRefTermExample.generated.h"

UCLASS()
class UAutoCreateRefTermExample : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void SomeColorWithoutRef(const FLinearColor& Color) {}

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="Color"))
	void SomeColorWithRef(const FLinearColor& Color) {}
};
