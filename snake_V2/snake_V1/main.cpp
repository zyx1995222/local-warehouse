# include "iostream"
# include "Snake.h"
# include "Utils.h"
# include "Food.h"
# include "time.h"

int main(void)
{
	
	initgraph(940,580);
	srand((unsigned)time(NULL));
	Snake s(10);
	Food f(180,180);
	initFood(f);
	InitSnake(s);
	bool isGameover = false;

	//Main circulation
	while (!isGameover)
	{
		judgement(s);
		cleardevice();
		isGameover =  SnakeRun(s,f);
		initFood(f);
		InitSnake(s);
		Sleep(100);
	}

	settextstyle(100, 0, _T("ËÎÌו"));
	outtextxy(270, 220, _T("Game Over"));

	system("pause");
	closegraph();
	return 0;
}




