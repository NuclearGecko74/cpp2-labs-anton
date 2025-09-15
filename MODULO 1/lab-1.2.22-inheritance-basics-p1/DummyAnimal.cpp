#include "DummyAnimal.h"

#include <iostream>

DummyAnimal::DummyAnimal() :
	FarmAnimal(10.0)
{
	std::cout << "DummyAnimal constructor called.\n";
}
