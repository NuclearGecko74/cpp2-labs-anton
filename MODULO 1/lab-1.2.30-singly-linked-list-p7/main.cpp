#include <iostream>

using namespace std;

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
	LinkedList list1;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	cout << "list1" << endl;
	printList(list1);
	cout << endl;

	LinkedList list2(list1);
	cout << "list2" << endl;
	printList(list2);
	cout << endl;

	list1.insert_at(1, 6);
	list2.remove_at(2);

	cout << "list1" << endl;
	printList(list1);
	cout << "\nlist2" << endl;
	printList(list2);
	cout << endl;

	return EXIT_SUCCESS;
}