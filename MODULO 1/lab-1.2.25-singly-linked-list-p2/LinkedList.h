#pragma once

#include "Node.h"

class LinkedList
{
private:
	Node* head;
public:
	LinkedList();
	~LinkedList();

	void push_front(int value);
	bool pop_front(int& value);

	bool pop_back(int& value);

	inline bool isEmpty() const { return head == nullptr; }

	void displayList() const;
};