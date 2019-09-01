#ifndef _CONSOLETOOLS_H_
#define _CONSOLETOOLS_H_
#include <Windows.h>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
Simplify console's IO stream and graphics output;
*/

#define MoveDown 80 //Control stuff move down.
#define MoveUp 72// Control stuff move up.
#define MoveRight 77// Control stuff move right.
#define MoveLeft 75// Control stuff move left.
#define Space 32//Control stuff press space.

#define TM_Width(x,length) (x)+(length)-1//Text move rectangle width.
#define TM_Height(y,length) (y)+(length)-1//Text move rectangle height.

#define StrengthenColor(Color) (Color) | (FOREGROUND_INTENSITY)//Text highlighted.
#define Random(a,b)  (rand() % ((b)-(a)+1))+ (a)//Get the random integer number[a,b].

//The string struct on the console.
typedef struct
{
	COORD pos;
	char str;
	
} COORD_char;

typedef vector<COORD_char>::iterator vectorIt;
typedef vector<COORD_char>  *posListType;

extern char strs[][20];
extern vector<COORD_char> * posList; 
extern list<posListType> posListDataBase;
extern char * selectedString;
extern int countSelectedCorrect;
extern HANDLE semaphore_main;//main lock;
extern HANDLE semaphore_cursor;//cursorControl thread lock;
extern HANDLE semaphore_countDown;//count down thread lock;
extern HANDLE semaphore_cursorWithCount;//The thread lock that commuicate between cursor control and count down thread;
extern HANDLE semaphore_producePosList;//The thread lock that commuicate between cursor control and count down thread;




class ConsoleTools
{
public:
	ConsoleTools();
	~ConsoleTools();
public:
	//Just get the last ASCII of the press keys.
	int GetChar();
	//Set console window size.
	void setConsoleSize(int width,int height);
	//Control cursor moving.
	void cursorControl();
	//Console output string at the specified location.
	void writeText(const char * str,COORD position,const WORD textAttribute);
	//View the corresponding ASCII in console by pressing the keyboard.
	void showKeyASCII();
	//Control text moving.     Note: Do not used int the project.
	void textControl(const char * str,COORD initPosition,WORD textAttribute);
	//Get console buffer attribute.
	WORD getConsoleAttribute();
	//Make a string flicker on screen.
	void singleStrFlicker(const char * str,COORD stringPosition,unsigned speed);
	//Mutiple string flicker on the console.
	void mutipleStrFlicker();
	//Set Cursor position.
	void initCursorPosition(const short x,const short y);
	//Console top words writing.
	void TopWriting();
	//Converts char to string.
	const char * charToString(char cha);
	//Time count down.
	void countDown(int maxTime);
	//Produce posList
	void producePosList(
						const int produceQuantity,
						unsigned X,
						unsigned Y,
						unsigned width,
						unsigned height,
						unsigned int FlickerQuantity
						);
	

private:
	void cursorMoveRight(int runStep);//Control cursor run to move right.
	void cursorMoveLeft(int runStep);//Control cursor run to move left.
	void cursorMoveDown(int runStep);//Control cursor to move down.
	void cursorMoveUp(int runStep);//Control cursor to move up.
	
	//Control text run to move down;     Note: Do not used int the project.
	COORD textMoveDown(COORD position,int StringLength,int runStep);
	//Control text run to move up;       Note: Do not used int the project.
	COORD textMoveUp(COORD position,int StringLength,int runStep);
	//Control text run to move right;    Note: Do not used int the project.
	COORD textMoveRight(COORD position,int StringLength,int runStep);
	//Control text run to move Left;     Note: Do not used int the project.
	COORD textMoveLeft(COORD position,int StringLength,int runStep);

	//Add a COOR element the X and Y values which is a random integer number to a vector container.
	bool AddUnrepititionCOOD(vector<COORD_char> & posList,int X,int Y);
	//Get a single string from 'a' to 'z'.
	char * getSingleChar();
	//Get current cursor position.
	COORD getCurrentCursorPosition();
	//Compare the top console char and the selected char by pressing space.
	bool MatchStrs(COORD_char pos_char);

public:
	//Text Attribute.
	const WORD Color_Foreground_Red;
	const WORD Color_Foreground_Blue;
	const WORD Color_Foreground_Green;
	const WORD Color_Foreground_Purple;
	const WORD Color_Foreground_Cyan;
	const WORD Color_Foreground_Yellow;
	const WORD Color_Foreground_Gray;

	const WORD Color_Background_Red;
	const WORD Color_Background_Blue;
	const WORD Color_Background_Green;
	const WORD Color_Background_Purple;
	const WORD Color_Background_Cyan;
	const WORD Color_Background_Yellow;
	const WORD Color_Background_Gray;

	const WORD Highlight_Color_Foreground_Red;
	const WORD Highlight_Color_Foreground_Blue;
	const WORD Highlight_Color_Foreground_Green;
	const WORD Highlight_Color_Foreground_Purple;
	const WORD Highlight_Color_Foreground_Cyan;
	const WORD Highlight_Color_Foreground_Yellow;
private:
	CONSOLE_SCREEN_BUFFER_INFO consoleInformation;//console info HANDLE.
	HANDLE handle_out;//output HANDLE.
	
	char c[2];
};





#endif