# pragma once

class Food
{
public:
	Food(int x,int y);
	~Food();
public:
	void setX(int x);//Set food x coordinate.
	int getX();//Get food y coordinate.

	void setY(int y);//Set food y coordinate.
	int getY();//Get food y coordinate.

	int getWidth();//Get food width.
	int getHeight();//Get food height.

private:
	int x;//Food x coordinate.
	int y;//Food y coordinate
};

