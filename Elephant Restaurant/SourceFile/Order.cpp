# include "Order.h"
# include "iostream"
using namespace std;

Order::Order()
{
	OrderNumber = 0;
	food = NULL;
}

Order::Order(int OrderNumber,int* food,int foodCount)
{
	this->OrderNumber = OrderNumber;
	this->food = food;
	this->foodCount = foodCount;
}


Order::~Order()
{
	
}

int Order::getOrderNumber()
{
	return OrderNumber;
}

void Order::setOrderNumber(int OrderNumber)
{
	this->OrderNumber = OrderNumber;
}

int* Order::getFood()
{
	return food;
}

void Order::setFood(int* food)
{
	this->food = food;
}

int Order::getFoodCount()
{
	return foodCount;
}

void Order::setFoodCount(int foodCount)
{
	this->foodCount = foodCount;
}