#include <iostream>

#include "ShopItemOrder.h"

void printOrder(ShopItemOrder itemOrder)
{
	std::cout << itemOrder.getNumberOfItems() << " x '" << itemOrder.getName() << "' = " << itemOrder.getTotalPrice() << '\n';
}

int main()
{
	ShopItemOrder orderTShirts("T-shirt mens black size M", 23.4f, 3);
	ShopItemOrder orderJeans("Jeans mens blue size M", 42.2f, 2);

	printOrder(orderTShirts);
	printOrder(orderJeans);
}