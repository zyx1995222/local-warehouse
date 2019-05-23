# include "Food.h"

Food::Food(int x,int y)
{
	this->x = x;
	this->y = y;
}

Food::~Food()
{
}

void Food::setX(int x)
{
	this->x = x;
}

int Food::getX()
{
	return x;
}

void Food::setY(int y)
{
	this->y = y;
}

int Food::getY()
{
	return y;
}

int Food::getHeight()
{
	return y+10;//Food's shape is a rectangle from 10 ¡Á 10.
}

int Food::getWidth()
{
	return x+10;//Food's shape is a rectangle from 10 ¡Á 10.
}