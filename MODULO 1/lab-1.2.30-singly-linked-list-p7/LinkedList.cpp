#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

LinkedList::LinkedList(LinkedList& list)
{
	head = nullptr;
	tail = nullptr;
	length = 0;

	Node* current = list.head;
	while (current != nullptr) 
	{
		this->push_back(current->value);
		current = current->next;
	}
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

bool LinkedList::pop_front()
{
	if (isEmpty()) { return false; }

	Node* temp = head;
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

bool LinkedList::pop_back()
{
	if (isEmpty()) {
		return false;
	}

	if (head->next == nullptr) {
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

	pre->next = nullptr;
	delete temp;
	tail = pre;
	length--;
	return true;
}

int LinkedList::at(int index) const
{
	if (index < 0 || index >= length)
	{
		std::cerr << "Index out of bounds!\n";
		std::abort();
	}

	Node* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp->value;
}

bool LinkedList::insert_at(int index, int value)
{
	if (index < 0 || index > length) { return false; }

	if (index == 0)
	{
		push_front(value);
		return true;
	}

	if (index == length)
	{
		push_back(value);
		return true;
	}

	Node* newNode = new Node(value);
	Node* temp = get(index - 1);
	newNode->next = temp->next;
	temp->next = newNode;
	length++;
	return true;
}

void LinkedList::remove_at(int index)
{
	if (index == 0 || index >= length) { return; }

	if (index == 0)
	{
		pop_front();
		return;
	}

	if (index == length - 1)
	{
		pop_back();
		return;
	}

	Node* prev = get(index - 1);
	Node* temp = prev->next;
	prev->next = temp->next;
	delete temp;
	length--;
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

Node* LinkedList::get(int index)
{
	if (index < 0 || index >= length)
	{
		std::cerr << "Index out of bounds!\n";
		std::abort();
	}

	Node* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}