#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <process.h>
#include <time.h>
#include <queue>
#include "ConsoleTools.h"
#include "ThreadFunction.h"
using namespace std;

//Produce posList
unsigned __stdcall Thread3_CreatePosList_DataBase(void*)
{
    ConsoleTools con;
    while (true)
    {
        WaitForSingleObject(semaphore_producePosList, INFINITE);
        con.producePosList(5,0, 5, 160, 40, 150);
    }
    
    return 0;
}


//Control cursor moving thread.
unsigned __stdcall Thread1_cursorControl(void *)
{
    ConsoleTools con;
    while (true)
    {
        //Wait release this thread lock from other thread.
        WaitForSingleObject(semaphore_cursor, INFINITE);
        con.cursorControl();
        showByCursorControl();
    }
    
    return 0;
}


//Time count down thread.
unsigned __stdcall Thread2_countDown(void *)
{
    ConsoleTools con;
    while (true)
    {
        //Wait release this thread lock from other thread.
        WaitForSingleObject(semaphore_countDown, INFINITE);
        con.countDown(100);
        showByCountDown();
        
    }

    return 0;
}


//Console UI show order from Thread2.
void showByCountDown()
{
    srand((unsigned)time(NULL));
    ConsoleTools con;

    system("cls");
    con.TopWriting();
    con.initCursorPosition(0, 5);
    con.mutipleStrFlicker();
    ReleaseSemaphore(semaphore_countDown, 1, NULL);

}


//Console UI show order from Thread1.
void showByCursorControl()
{
    WaitForSingleObject(semaphore_cursorWithCount, INFINITE);

    srand((unsigned)time(NULL));
    ConsoleTools con;

    system("cls");
    con.TopWriting();
    con.initCursorPosition(0, 5);
    con.mutipleStrFlicker();
    ReleaseSemaphore(semaphore_cursor, 1, NULL);

    ReleaseSemaphore(semaphore_cursorWithCount, 1, NULL);

}
