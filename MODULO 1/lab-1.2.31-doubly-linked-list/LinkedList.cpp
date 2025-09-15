#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

LinkedList::LinkedList(const LinkedList& other)
{
	head = nullptr;
	tail = nullptr;
	length = 0;

	Node* current = other.head;
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
	Node* newNode = new Node(value);

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	length++;
}

bool LinkedList::pop_front(int& value)
{
	if (isEmpty()) { return false; }

	Node* temp = head;
	value = temp->value;
	head = head->next;

	if (head != nullptr) 
	{
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}

	delete temp;
	length--;
	return true;
}

bool LinkedList::pop_front()
{
	if (isEmpty()) { return false; }

	Node* temp = head;
	head = head->next;

	if (head != nullptr) 
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}

	delete temp;
	length--;
	return true;
}

void LinkedList::push_back(int value)
{
	Node* newNode = new Node(value);

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	length++;
}

bool LinkedList::pop_back(int& value)
{
	if (isEmpty())
	{
		return false;
	}

	Node* temp = tail;
	value = temp->value;

	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete temp;
	length--;
	return true;
}

bool LinkedList::pop_back()
{
	if (isEmpty()) 
	{
		return false;
	}

	Node* temp = tail;

	if (head == tail) 
	{
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete temp;
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

	Node* temp;
	if (index > length / 2) 
	{
		temp = tail;
		for (int i = length - 1; i > index; i--)
		{
			temp = temp->prev;
		}
	}
	else 
	{
		temp = head;
		for (int i = 0; i < index; i++) 
		{
			temp = temp->next;
		}
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
	Node* current = get(index);

	newNode->next = current;
	newNode->prev = current->prev;
	current->prev->next = newNode;
	current->prev = newNode;

	length++;
	return true;
}

bool LinkedList::remove_at(int index)
{
	if (index < 0 || index >= length) { return false; }

	if (index == 0)
	{
		pop_front();
		return true;
	}

	if (index == length - 1)
	{
		pop_back();
		return true;
	}

	Node* current = get(index);
	current->prev->next = current->next;
	current->next->prev = current->prev;

	delete current;
	length--;
	return true;
}

void LinkedList::displayList() const
{
	if (head == nullptr) 
	{
		std::cout << "List is empty\n";
		return;
	}

	Node* temp = head;
	while (temp) 
	{
		std::cout << temp->value << '\n';
		temp = temp->next;
	}
}

Node* LinkedList::get(int index) const
{
	if (index < 0 || index >= length)
	{
		std::cerr << "Index out of bounds!\n";
		std::abort();
	}

	Node* temp;
	if (index > length / 2)
	{
		temp = tail;
		for (int i = length - 1; i > index; i--)
		{
			temp = temp->prev;
		}
	}
	else 
	{
		temp = head;
		for (int i = 0; i < index; i++) 
		{
			temp = temp->next;
		}
	}
	return temp;
}