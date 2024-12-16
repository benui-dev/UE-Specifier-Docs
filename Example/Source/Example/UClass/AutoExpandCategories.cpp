#include "AutoExpandCategories.h"

AExampleE::AExampleE()
{
	PrimaryActorTick.bCanEverTick = false;

	ExampleComponent = CreateDefaultSubobject<UExampleComponent>(TEXT("ExampleComponent"));
}
