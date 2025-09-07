#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	int    age;
	// Your code here
	float height; // in m
	float weight; // in kg
	bool bIsStudent;
};

void print(const Person* person)
{
	cout << person->name << " is " << person->age << " years old. "
		<< "Height: " << person->height << " m, "
		<< "Weight: " << person->weight << " kg, "
		<< "Student: " << (person->bIsStudent ? "yes" : "no") << endl;
}


int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.height = 1.75f;
	person.weight = 70.5f;
	person.bIsStudent = false;

	cout << "Meet " << person.name << endl;
	print(&person);

	// Your code here
	Person chepe;
	chepe.name = "Jose Carlos";
	chepe.age = 20;
	chepe.height = 1.80f;
	chepe.weight = 91.2f;
	chepe.bIsStudent = true;
	print(&chepe);

	return 0;
}