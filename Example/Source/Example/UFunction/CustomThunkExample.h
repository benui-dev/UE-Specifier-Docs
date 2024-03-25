#pragma once

#include "CustomThunkExample.generated.h"

UCLASS()
class UCustomThunkExample : public UObject
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, CustomThunk)
	float Sum(float A, double B);

private:
	DECLARE_FUNCTION(execSum);
};