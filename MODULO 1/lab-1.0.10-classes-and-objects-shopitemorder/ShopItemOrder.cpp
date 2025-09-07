#include "ShopItemOrder.h"

ShopItemOrder::ShopItemOrder(std::string_view name, float unitPrice, int numberOfItems)
{
	this->name = name;
	this->unitPrice = unitPrice;
	this->numberOfItems = numberOfItems;
}

void ShopItemOrder::setUnitPrice(const float unitPrice)
{
	if (unitPrice > 0)
	{
		this->unitPrice = unitPrice;
	}
}

void ShopItemOrder::setNumberOfItems(const int numberOfItems)
{
	if (numberOfItems > 0)
	{
		this->numberOfItems = numberOfItems;
	}
}