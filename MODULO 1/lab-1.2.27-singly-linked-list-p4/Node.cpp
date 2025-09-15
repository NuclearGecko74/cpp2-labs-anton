#include "Node.h"

// #include <iostream>

Node::Node(int value, Node* next) :
	value{ value }, next{ next }
{
	// std::cout << "+Node\n";
}

Node::Node(int value) :
	Node(value, nullptr)
{

}

Node::Node() :
	Node(0, nullptr)
{

}

Node::~Node()
{
	// std::cout << "-Node\n";
}