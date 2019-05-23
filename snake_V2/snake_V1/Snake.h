# pragma once
# include "iostream"
# include "graphics.h"//This is a patterning library,download from https://easyx.cn/.
# include "conio.h"
# include "vector"
# include "deque"
# include "algorithm"
# include "Food.h"
using namespace std;

# define up 72
# define down 80
# define left 75
# define right 77

/*
Snake is the important class at this project.
*/
class Snake
{
	
public:
	//Internal class;
	class SnakeNode
	{
	public:
		SnakeNode(int x,int y);//Init a node;

	public:
		void printF();//Print x&y on console.
		int getX();//Get private property x by public function.
		int getY();//Get private property x by public function.
		void setXY(int x,int y);//Set private property x&y by public function.
		int getWidth();//Get snake node width by public function.
		int getHeight();//Get snake node height by public function.

	private:
		int x;//Node x coordinate.
		int y;//Node y coordinate.
	};

//------------------------------------------------------------------------------

public:
	Snake(int length);//Init a snake use the length sent;
	~Snake();

public:
	friend bool SnakeRun(Snake & snake,Food & food);
	friend bool isGameOver(int newHeadX,int newHeadY,Snake & snake);
public:
	void printF();//Print snake length on console;
	SnakeNode get(int index);//Index snake node.
	void set(int index,SnakeNode & node);//Update snake by index.
	int getDirection();//Get current direction of snake.
	void setDirection(int direction);//Set current direction of snake.
	int getLength();//Get snake length.
	bool addSnakeLen(int x,int y);//Add snake node.

private:
	int direction;//Snake run direction.
	deque<SnakeNode> SnakeContainer;//Snake's node is put in the double-end queue container.
};

typedef deque<Snake::SnakeNode>::iterator vectorIterator;

