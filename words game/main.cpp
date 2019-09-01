#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <process.h>
#include <time.h>
#include <vector>
#include <list>
#include "ConsoleTools.h"
#include "ThreadFunction.h"
using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));
	ConsoleTools con;
	con.setConsoleSize(160, 40); //Set console size.

	con.producePosList(1,0, 5, 160, 40, 150);

	con.TopWriting();
	con.initCursorPosition(0, 5);
	con.mutipleStrFlicker();

	HANDLE thread1 = (HANDLE)_beginthreadex(0, 0, Thread1_cursorControl, 0, 0, 0); //Begin a new thread1.
	HANDLE thread2 = (HANDLE)_beginthreadex(0, 0, Thread2_countDown, 0, 0, 0);	 //Begin a new thread2.
	HANDLE thread3 = (HANDLE)_beginthreadex(0, 0, Thread3_CreatePosList_DataBase, 0, 0, 0);	 //Begin a new thread3.
    
	//Close thread handle;
	CloseHandle(thread1);
	CloseHandle(thread2);
	CloseHandle(thread3);

	WaitForSingleObject(semaphore_main, INFINITE);

	return 0;
}