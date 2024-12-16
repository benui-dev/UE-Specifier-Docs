#pragma once

#include "Engine/DataTable.h"
#include "DataTableImportOptional.generated.h"

USTRUCT()
struct FDataTableImportOptionalExampleRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere, meta=(DataTableImportOptional=true))
	FString NameOld;

	UPROPERTY(EditAnywhere)
	int32 Happiness;
};