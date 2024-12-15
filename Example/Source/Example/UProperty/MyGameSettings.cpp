#include "MyGameSettings.h"

UMyGameSettings::UMyGameSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Large text for where settings should be grouped on the left
	CategoryName = "Project";

	// Smaller sub-heading for grouping
	SectionName = "Some Custom Settings";
}
