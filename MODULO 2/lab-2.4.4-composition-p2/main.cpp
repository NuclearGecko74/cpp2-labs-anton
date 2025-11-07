#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Engine {
private:
	double m_version;

public:
	Engine(double version) : m_version(version) {}
	void print() const 
	{
		std::cout << "Engine: " << std::fixed << std::setprecision(1) << m_version << std::endl;
	}
};

class Wheel {
private:
	std::string m_size;

public:
	Wheel(std::string size) : m_size(size) {}
	void print() const
	{
		std::cout << "Wheel: " << m_size << std::endl;
	}
};

class Chassis {
private:
	std::string m_type;

public:
	Chassis(std::string type) : m_type(type) {}
	void print() const 
	{
		std::cout << "Chassis: " << m_type << std::endl;
	}
};

class Light {
private:
	std::string m_type;

public:
	Light(std::string type) : m_type(type) {}
	void print() const 
	{
		std::cout << "Light: " << m_type << std::endl;
	}
};

class Body {
private:
	std::string m_color;

public:
	Body(std::string color) : m_color(color) {}
	void print() const
	{
		std::cout << "Body: " << m_color << std::endl;
	}
};

class Car {
private:
	Engine m_engine;
	std::vector<Wheel> m_wheels;
	Chassis m_chassis;
	std::vector<Light> m_lights;
	Body m_body;

public:
	Car() : m_engine(1.0), m_chassis("Normal"), m_body("Black") 
	{

		for (int i = 0; i < 4; ++i)
		{
			m_wheels.emplace_back("16inches");
		}

		m_lights.emplace_back("Type 1");
		m_lights.emplace_back("Type 1");
		m_lights.emplace_back("Type 2");
		m_lights.emplace_back("Type 2");
		m_lights.emplace_back("Type 3");
		m_lights.emplace_back("Type 3");
		m_lights.emplace_back("Type 4");
		m_lights.emplace_back("Type 4");
		m_lights.emplace_back("Type 5");
		m_lights.emplace_back("Type 5");
	}

	void print() const
	{
		m_engine.print();
		for (const auto& wheel : m_wheels) 
		{
			wheel.print();
		}
		m_chassis.print();
		for (const auto& light : m_lights)
		{
			light.print();
		}
		m_body.print();
	}
};

int main() 
{
	Car myCar;
	myCar.print();
	return 0;
}