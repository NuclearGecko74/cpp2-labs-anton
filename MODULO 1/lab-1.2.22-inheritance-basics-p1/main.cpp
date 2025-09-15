#include <iostream>

#include "FarmAnimal.h"
#include "DummyAnimal.h"
#include "DoublingAnimal.h"

static void printConsumption(const FarmAnimal& animal);

int main()
{
	FarmAnimal animalA(5);
	DummyAnimal animalB;
	DoublingAnimal animalC(21);

	std::cout << "animalA consumes " << animalA.getWaterConsumption()
		<< " liters of water.\n";
	std::cout << "What about the others?\n";

	printConsumption(animalB);
	printConsumption(animalC);
	return EXIT_SUCCESS;
}

void printConsumption(const FarmAnimal& animal)
{
	std::cout << "This animal consumes " << animal.getWaterConsumption()
		<< " liters of water\n";
}