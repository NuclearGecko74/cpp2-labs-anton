#include "Node.h"

Node::Node(int value, Node* next) :
	value{ value }, next{ next }
{

}

Node::Node(int value) :
	Node(value, nullptr)
{

}

Node::Node() :
	Node(0, nullptr)
{

}