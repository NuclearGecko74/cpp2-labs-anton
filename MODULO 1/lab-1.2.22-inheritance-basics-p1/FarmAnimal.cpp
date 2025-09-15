#include "FarmAnimal.h"

#include <iostream>

FarmAnimal::FarmAnimal(double waterConsumption) :
	waterConsumption {waterConsumption}
{
	std::cout << "FarmAnimal constructor called with argument: " << waterConsumption << std::endl;
}
