#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	if (!isEmpty())
	{
		Node* temp = head;
		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
}

void LinkedList::push_front(int value)
{
	Node* temp = new Node(value);
	temp->next = head;
	head = temp;
}

bool LinkedList::pop_front(int& value)
{
	if (head == nullptr) { return false; }

	Node* temp = head;
	value = temp->value;
	head = head->next;
	delete temp;

	return true;
}

bool LinkedList::pop_back(int& value)
{
	if (head == nullptr) {
		return false;
	}

	if (head->next == nullptr) {
		value = head->value;
		delete head;
		head = nullptr;
		return true;
	}

	Node* temp = head;
	Node* pre = nullptr;

	while (temp->next != nullptr) {
		pre = temp;
		temp = temp->next;
	}

	value = temp->value;
	pre->next = nullptr;
	delete temp;

	return true;
}

void LinkedList::displayList() const
{
	if (isEmpty())
	{
		std::cout << "List is empty\n";
	}

	Node* temp = head;
	while (temp)
	{
		std::cout << temp->value << '\n';
		temp = temp->next;
	}
}