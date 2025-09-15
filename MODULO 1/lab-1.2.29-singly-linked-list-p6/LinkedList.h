#pragma once

#include "Node.h"

class LinkedList
{
private:
	Node* head;
	Node* tail;

	size_t length;
public:
	LinkedList();
	~LinkedList();

	void push_front(int value);
	bool pop_front(int& value);

	void push_back(int value);
	bool pop_back(int& value);

	bool pop_front();
	bool pop_back();

	int at(int index) const;

	bool insert_at(int index, int value);
	void remove_at(int index);

	inline bool isEmpty() const { return head == nullptr; }
	inline size_t size() const { return length; }

	void displayList() const;

private:
	Node* get(int index);
};