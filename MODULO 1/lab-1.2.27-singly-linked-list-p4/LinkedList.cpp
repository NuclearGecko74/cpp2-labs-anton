#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
	length = 0;
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
	length++;
}

bool LinkedList::pop_front(int& value)
{
	if (isEmpty()) { return false; }

	Node* temp = head;
	value = temp->value;
	head = head->next;
	delete temp;

	length--;
	return true;
}

void LinkedList::push_back(int value)
{
	if (isEmpty())
	{
		head = new Node(value);
		return;
	}

	Node* temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new Node(value);
}

bool LinkedList::pop_back(int& value)
{
	if (isEmpty()) {
		return false;
	}

	if (head->next == nullptr) {
		value = head->value;
		delete head;
		head = nullptr;
		length--;
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

	length--;
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