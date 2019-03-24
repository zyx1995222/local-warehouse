# pragma once
# include "Order.h"
# include "Customer.h"

class RestaurantView
{
public:
	RestaurantView();
	~RestaurantView();
	int createView();
	Order* createFood();
	Order* orderFoods();
	bool isBool(int);
	void showOrder(int,Customer*);
private:
	int oNumber;
};



