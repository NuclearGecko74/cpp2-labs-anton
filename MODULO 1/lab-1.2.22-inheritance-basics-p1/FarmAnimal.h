#pragma once
class FarmAnimal
{
private:
	double waterConsumption;
public:
	FarmAnimal(double waterConsumption);

	inline double getWaterConsumption() const { return waterConsumption; }
};

