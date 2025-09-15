#pragma once

class LinkedList;

class Node
{
private:
	int value;
	Node* next;
	Node* prev;

public:
	Node(int value, Node* next, Node* prev);
	Node(int value);
	Node();

	~Node();

	friend class LinkedList;
};