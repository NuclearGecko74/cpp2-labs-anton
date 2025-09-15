#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FarmAnimal {
public:
	FarmAnimal(double water_consumption) : water_consumption(water_consumption) {}
	double getWaterConsumption() const { return water_consumption; }
private:
	double water_consumption;
};

class Sheep : public FarmAnimal
{
public:
	Sheep(double weight) : FarmAnimal(1.1 * weight / 10.0) {}
};

class Horse : public FarmAnimal
{
public:
	Horse(double weight) : FarmAnimal(6.8 * weight / 100.0) {}
};

class Cow : public FarmAnimal
{
public:
	Cow(double weight) : FarmAnimal(8.6 * weight / 100.0) {}
};

class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator() : total_consumption(0) {}
	double getTotalConsumption() const { return total_consumption; }
	void addConsumption(const FarmAnimal& animal)
	{
		total_consumption += animal.getWaterConsumption();
	}
private:
	double total_consumption;
};

int main()
{
	ConsumptionAccumulator accumulator;
	string line;

	cout << "Enter animal and weight (e.g., 'cow 500'). Press Enter on an empty line to finish.\n";

	while (getline(cin, line) && !line.empty()) {
		stringstream ss(line);
		string animal_type;
		double weight;

		ss >> animal_type >> weight;

		if (animal_type == "cow") {
			Cow cow(weight);
			accumulator.addConsumption(cow);
		}
		else if (animal_type == "sheep") {
			Sheep sheep(weight);
			accumulator.addConsumption(sheep);
		}
		else if (animal_type == "horse") {
			Horse horse(weight);
			accumulator.addConsumption(horse);
		}
		else {
			cout << "Warning: Unknown animal type '" << animal_type << "'. Skipping.\n";
		}
	}

	cout << accumulator.getTotalConsumption();

	return 0;
}