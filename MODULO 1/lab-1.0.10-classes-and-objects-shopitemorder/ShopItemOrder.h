#pragma once

#include <iostream>

class ShopItemOrder
{
private:
	std::string name;
	float unitPrice;
	int numberOfItems;

public:
	ShopItemOrder(std::string_view name, float unitPrice, int numberOfItems);

	// Getters
	inline std::string_view getName() const { return name; }
	inline float getUnitPrice() const { return unitPrice; }
	inline int getNumberOfItems() const { return numberOfItems; }

	inline float getTotalPrice() const { return unitPrice * numberOfItems; }

	// Setters
	void setName(std::string_view name) { this->name = name; }
	void setUnitPrice(const float unitPrice);
	void setNumberOfItems(const int numberOfItems);
};
