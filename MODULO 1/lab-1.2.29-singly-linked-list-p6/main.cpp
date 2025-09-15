#include <iostream>

#include "LinkedList.h"

void printList(LinkedList& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << "list[" << i << "] == " << list.at(i) << std::endl;
	}
}


int main()
{
	LinkedList list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	printList(list);
	std::cout << std::endl;

	list.remove_at(2);
	printList(list);
	std::cout << std::endl;

	list.insert_at(1, 6);
	printList(list);

	return EXIT_SUCCESS;
}