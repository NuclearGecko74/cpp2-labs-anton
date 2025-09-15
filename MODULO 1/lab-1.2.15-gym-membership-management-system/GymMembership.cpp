#include "GymMembership.h"

GymMembership::GymMembership(int id, const std::string& name) :
	id(id), name(name), subscriptionMonths(0)
{

}

void GymMembership::printStatus() const
{
	std::cout << "Member " << id << " : " << name 
			  << ", subscription valid for " 
			  << subscriptionMonths << " months\n";
}

void GymMembership::extendSubscription(int months)
{
	if (months <= 0)
	{
		std::cout << "Cannot perform this operation! Invalid number of months.\n";
		return;
	}
	this->subscriptionMonths += months;
}

void GymMembership::cancelSubscription()
{
	this->subscriptionMonths = 0;
}
