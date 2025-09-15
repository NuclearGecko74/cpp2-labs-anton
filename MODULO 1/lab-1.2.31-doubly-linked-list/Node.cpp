#include "Node.h"

// #include <iostream>

Node::Node(int value, Node* next, Node* prev) :
	value{ value }, next{ next }, prev{ prev }
{
	// std::cout << "+Node\n";
}

Node::Node(int value) :
	Node(value, nullptr, nullptr)
{

}

Node::Node() :
	Node(0, nullptr, nullptr)
{

}

Node::~Node()
{
	// std::cout << "-Node\n";
}