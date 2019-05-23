# include "Utils.h"

/*
Init the patterning snake.
*/
void InitSnake(Snake & snake)
{
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
	for (int i = 0; i < snake.getLength(); i++)
	{
		//Snake coordiante.
		x = snake.get(i).getX();
		y = snake.get(i).getY();

		//Snake width&height(rectangle).
		width = snake.get(i).getWidth();
		height = snake.get(i).getHeight();

		if (i == 0)
		{
			//Snake head color is yellow.
			setfillcolor(YELLOW);
		}
		else
		{
			//Snake nodes color is green.
			setfillcolor(GREEN);
		}
		//Drawing snake with these property.
		solidrectangle(x,y,width,height);
	}
}


void judgement(Snake & snake)
{
	if (_kbhit())
		{
			int move = _getch();
			switch (move)
			{
			case right:
				if (snake.getDirection() == left)
				{
					//Can not change the snake direction if next direction is reverse with now.
					break;
				}
				snake.setDirection(move);
				break;
			case down:
				if (snake.getDirection() == up)
				{
					//Can not change the snake direction if next direction is reverse with now.
					break;
				}
				snake.setDirection(move);
				break;
			case up:
				if (snake.getDirection() == down)
				{
					//Can not change the snake direction if next direction is reverse with now.
					break;
				}
				snake.setDirection(move);
				break;
			case left:
				if (snake.getDirection() == right)
				{
					//Can not change the snake direction if next direction is reverse with now.
					break;
				}
				snake.setDirection(move);
				break;
			default:
				break;
			}
		}

}

bool SnakeRun(Snake & snake,Food & food)
{
	Snake::SnakeNode SnakeHead = snake.get(0);//Get the snake head.

	int newHeadX = 0;
	int newHeadY = 0;

	//Change snake direction.
	switch (snake.getDirection())
	{
	case right:
		newHeadX = SnakeHead.getX()+10;
		newHeadY = SnakeHead.getY();
		break;
	case down:
		newHeadX = SnakeHead.getX();
		newHeadY = SnakeHead.getY()+10;
		break;
	case left:
		newHeadX = SnakeHead.getX()-10;
		newHeadY = SnakeHead.getY();
		break;
	case up:
		newHeadX = SnakeHead.getX();
		newHeadY = SnakeHead.getY()-10;
		break;
	default:
		break;
	}

	//Judge if snake's next step have game over.
	 bool judgeIsGameOver = isGameOver(newHeadX,newHeadY,snake);
	 if (judgeIsGameOver)
	 {
		 return true;
	 }
	
	//Add a new snake head,old head will be transform second node.
	Snake::SnakeNode NewSnakeHead(newHeadX,newHeadY);

	
	if (newHeadX == food.getX() && newHeadY == food.getY())
	{
		//Reset food coordinate.
		food.setX((rand() % 93)*10);
		food.setY((rand() % 57)*10);

		//If next position have food,just insert a new snake head of the queue head and not erase the end element.
		snake.SnakeContainer.push_front(NewSnakeHead);

		return false;
	}
	else
	{
		//If next position have not food,insert a new snake head of the queue head and erase the end element.
		snake.SnakeContainer.push_front(NewSnakeHead);
		snake.SnakeContainer.pop_back();

		return false;
	}

	return false;
	

}

bool isGameOver(int newHeadX,int newHeadY,Snake & snake)
{
	//Snake touch the bound,game over.
	if (newHeadX > 930)
	{
		return true;
		//newHeadX = 0;
	}
	else if(newHeadY > 570)
	{
		return true;
		//newHeadY = 0;
	}
	else if(newHeadX < 0)
	{
		return true;
		//newHeadX = 940;
	}
	else if(newHeadY < 0)
	{
		return true;
		//newHeadY = 580;
	}

	//Snake run into oneself body,game over.
	for(vectorIterator it = snake.SnakeContainer.begin();it != snake.SnakeContainer.end();it++)
	{
		if (it->getX() == newHeadX && it->getY() == newHeadY)
		{
			return true;
		}
	}

	return false;


}

//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

void initFood(Food & food)
{
	setfillcolor(RED);
	solidrectangle(food.getX(),food.getY(),food.getWidth(),food.getHeight());
}