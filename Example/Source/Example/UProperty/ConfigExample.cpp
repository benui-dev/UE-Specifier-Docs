#include "ConfigExample.h"

UGameConfigExample::UGameConfigExample()
{
	CategoryName = "Example Project";
	SectionName = "Config Example";
}

UGameDefaultConfigExample::UGameDefaultConfigExample(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

UBaconEggDefaultConfigExample::UBaconEggDefaultConfigExample()
{
	CategoryName = "Example Project";
}

