# pragma once
# include "Snake.h"
# include "Food.h"

void judgement(Snake & snake);//Receive the keyboard input,then judge snake direction.
void InitSnake(Snake & snake);//Init the patterning snake.
bool SnakeRun(Snake & snake,Food & food);//Snake running.
void initFood(Food & food);//Draw food.
bool isGameOver(int newHeadX,int newHeadY,Snake & snake);//Judge if game have over.