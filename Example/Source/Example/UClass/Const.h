#pragma once

#include "UObject/Object.h"
#include "Const.generated.h"

UCLASS(Const, Blueprintable)
class UConstExample : public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SomeNumber = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SomeText = "Hello World!";

	/** Even though this is marked as BlueprintReadWrite, the UCLASS(Const) changes it to BlueprintReadOnly */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TextWithinExample = "Hello World!";

	UFUNCTION(BlueprintImplementableEvent)
	void MyBlueprintImplementableEvent() const;

	UFUNCTION(BlueprintNativeEvent)
	void MyBlueprintNativeEvent() const;
};
