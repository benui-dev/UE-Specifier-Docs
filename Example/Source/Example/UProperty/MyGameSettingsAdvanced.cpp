#include "MyGameSettingsAdvanced.h"

FName UMyGameSettingsAdvanced::GetCategoryName() const
{
	return TEXT("Project");
}

#if WITH_EDITOR
FText UMyGameSettingsAdvanced::GetSectionText() const
{
	return NSLOCTEXT("MyGameSettingsAdvanced", "SomeDoggySettings", "Doggy Settings");
}

FText UMyGameSettingsAdvanced::GetSectionDescription() const
{
	return NSLOCTEXT("MyGameSettingsAdvanced", "SomeDoggySettingsDescription", "Everything related to dogs within the game.");
}
#endif