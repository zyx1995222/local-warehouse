# include "iostream"
# include "Customer.h"
using namespace std;

Customer::Customer()
{
	order = NULL;
}

Customer::Customer(Order* order)
{
	this->order = order;
}


Customer::~Customer()
{

}

Order* Customer::getOrder()
{
	return order;
}

void Customer::setOrder(Order* order)
{
	this->order = order;
}