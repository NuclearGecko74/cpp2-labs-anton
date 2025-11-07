#include <iostream>

class BaseTree {
public:
	virtual void draw() {}
};

class SimpleTree : public BaseTree
{

public:

	void draw() override
	{
		std::cout << " /\\\n";
		std::cout << "//\\\\\n";
	}

};

class StarTree : public BaseTree
{

public:

	void draw() override
	{
		std::cout << " /\\\n";
		std::cout << "/**\\\n";
	}

};

class PlusTree : public BaseTree
{

public:

	void draw() override
	{
		std::cout << " /\\\n";
		std::cout << "/++\\\n";
	}

};

int main()
{
	BaseTree* trees[3];

	SimpleTree* tree1 = new SimpleTree;
	StarTree* tree2 = new StarTree;
	PlusTree* tree3 = new PlusTree;

	trees[0] = tree1;
	trees[1] = tree2;
	trees[2] = tree3;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Drawing " << i + 1 << ": \n";
		trees[i]->draw();
	}
	return EXIT_SUCCESS;
}