#include <iostream>

#include "LinkedList.h"

int main()
{
	LinkedList list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);

	int value = 0;
	while (list.pop_front(value))
	{
		std::cout << value << std::endl;
	}
	return 0;

	return EXIT_SUCCESS;
}