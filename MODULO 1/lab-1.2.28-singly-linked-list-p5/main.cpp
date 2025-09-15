#include <iostream>

#include "LinkedList.h"

int main()
{
	LinkedList list;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);

	int value = 0;
	while (list.pop_back(value))
	{
		std::cout << value << std::endl;
	}
	return EXIT_SUCCESS;
}