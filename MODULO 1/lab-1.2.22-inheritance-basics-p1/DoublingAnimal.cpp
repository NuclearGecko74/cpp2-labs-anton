#include "DoublingAnimal.h"

#include <iostream>

DoublingAnimal::DoublingAnimal(double givenWaterConsumption) :
	FarmAnimal(2 * givenWaterConsumption)
{
	std::cout << "DoublingAnimal constructor called with argument: " << givenWaterConsumption << '\n';
}