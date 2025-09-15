#pragma once

class LinkedList;

class Node
{
private:
	int value;
	Node* next;

public:
	Node(int value, Node* next);
	Node(int value);
	Node();

	friend class LinkedList;
};