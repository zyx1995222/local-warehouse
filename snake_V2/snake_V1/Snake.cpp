# include "Snake.h"



Snake::Snake(int length)
{
	direction = right;
	int x = 100;
	int y = 100;
	for (int i = 0; i < length; i++)
	{
		x-=10;
		SnakeNode node(x,y);
		SnakeContainer.push_back(node);
	}
}

Snake::~Snake()
{

}

void Snake::printF()
{
	cout<<SnakeContainer.size()<<endl;
}

Snake::SnakeNode Snake::get(int index)
{
	int i = 0;
	for(vectorIterator it = SnakeContainer.begin();it != SnakeContainer.end();it++)
	{
		if (index == i)
		{
			return *it;
		}
		i++;
	}
	throw 0;
}

void Snake::set(int index,Snake::SnakeNode & node)
{
	int i = 0;
	for(vectorIterator it = SnakeContainer.begin();it != SnakeContainer.end();it++)
	{
		if (index == i)
		{
			it->setXY(node.getX(),node.getY());
			return;
		}
		i++;
	}
}

int Snake::getDirection()
{
	return direction;
}

void Snake::setDirection(int direction)
{
	this->direction = direction;
}

int Snake::getLength()
{
	return SnakeContainer.size();
}


bool Snake::addSnakeLen(int x,int y)
{
	SnakeNode sn(x,y);
	SnakeContainer.push_back(sn);
	return true;
}

//-------------------------------------------------------------


Snake::SnakeNode::SnakeNode(int x,int y)
{
	this->x = x;
	this->y = y;
}

void Snake::SnakeNode::printF()
{
	cout<<x<<"---"<<y<<endl;
}

int Snake::SnakeNode::getX()
{
	return x;
}

int Snake::SnakeNode::getY()
{
	return y;
}

void Snake::SnakeNode::setXY(int x,int y)
{
	this->x = x;
	this->y = y;
}

int Snake::SnakeNode::getWidth()
{
	return x + 10;//Snake node shape is a rectangle from 10 ¡Á 10.
}

int Snake::SnakeNode::getHeight()
{
	return y + 10;//Snake node shape is a rectangle from 10 ¡Á 10.
}