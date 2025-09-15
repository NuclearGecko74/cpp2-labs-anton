#include <iostream>

#include "LinkedList.h"

int main()
{
	LinkedList list;

	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		std::cout << "pushed " << i << ", size: " << list.size() << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		int value;
		list.pop_front(value);
		std::cout << "popped " << i << ", size: " << list.size() << std::endl;
	}

	return EXIT_SUCCESS;
}