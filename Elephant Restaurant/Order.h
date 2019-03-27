# pragma once

class Order
{
public:
	Order();
	Order(int,int*,int);
	~Order();
	int getOrderNumber();
	void setOrderNumber(int);
	int* getFood();
	void setFood(int*);
	int getFoodCount();
	void setFoodCount(int);
private:
	int OrderNumber;
	int* food;
	int foodCount;
};

