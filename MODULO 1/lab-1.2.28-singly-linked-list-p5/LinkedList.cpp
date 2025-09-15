#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

LinkedList::~LinkedList()
{
	Node* current = head;
	while (current) 
	{
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
	tail = nullptr;
	length = 0;
}

void LinkedList::push_front(int value)
{
	if (isEmpty())
	{
		head = new Node(value);
		tail = head;
		length++;
		return;
	}

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
	Node* newNode = new Node(value);

	if (head == nullptr) 
	{
		head = newNode;
		tail = newNode;
	}
	else 
	{
		tail->next = newNode;
		tail = newNode;
	}
	length++;
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
	tail = pre;
	length--;
	return true;
}

void LinkedList::displayList() const
{
	if (head == nullptr) {
		std::cout << "List is empty\n";
		return;
	}

	Node* temp = head;
	while (temp) {
		std::cout << temp->value << '\n';
		temp = temp->next;
	}
}