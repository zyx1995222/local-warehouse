# pragma once
# include "Order.h"

class Customer
{
public:
	Customer();
	Customer(Order*);
	~Customer();
	Order* getOrder();
	void setOrder(Order*);

private:
	Order* order;
};

