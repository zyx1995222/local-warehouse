#include <conio.h>
#include <iostream>
#include <vector>
#include "ConsoleTools.h"
using namespace std;

char strs[17][20] = {
	"hello",	
	"world",	
	"random",	
	"zyx",		
	"china",	
	"chinese",
	"a",
	"ab",
	"c",
	"d",
	"too",
	"hi",
	"boy",
	"employee",
	"machine",
	"approve",
	"human"
	};
vector<COORD_char> * posList = NULL;
list<posListType> posListDataBase;
char * selectedString = NULL;
int countSelectedCorrect = 0;
HANDLE semaphore_main = CreateSemaphore(NULL,0,1,NULL);
HANDLE semaphore_cursor = CreateSemaphore(NULL,1,1,NULL);
HANDLE semaphore_countDown = CreateSemaphore(NULL,1,1,NULL);
HANDLE semaphore_cursorWithCount = CreateSemaphore(NULL,1,1,NULL);
HANDLE semaphore_producePosList = CreateSemaphore(NULL,1,1,NULL);


ConsoleTools::ConsoleTools() 
	: Color_Foreground_Red(FOREGROUND_RED)
	, Color_Foreground_Blue(FOREGROUND_BLUE)
	, Color_Foreground_Green(FOREGROUND_GREEN)
	, Color_Foreground_Purple(FOREGROUND_RED | FOREGROUND_BLUE)
	, Color_Foreground_Cyan(FOREGROUND_GREEN | FOREGROUND_BLUE)
	, Color_Foreground_Yellow(FOREGROUND_RED | FOREGROUND_GREEN)
	, Color_Foreground_Gray(FOREGROUND_INTENSITY)
	, Color_Background_Red(BACKGROUND_RED)
	, Color_Background_Blue(BACKGROUND_BLUE)
	, Color_Background_Green(BACKGROUND_GREEN)
	, Color_Background_Purple(BACKGROUND_RED | BACKGROUND_BLUE)
	, Color_Background_Cyan(BACKGROUND_GREEN | BACKGROUND_BLUE)
	, Color_Background_Yellow(BACKGROUND_RED | BACKGROUND_GREEN)
	, Color_Background_Gray(BACKGROUND_INTENSITY)
	, Highlight_Color_Foreground_Red(StrengthenColor(FOREGROUND_RED))
	, Highlight_Color_Foreground_Blue(StrengthenColor(FOREGROUND_BLUE))
	, Highlight_Color_Foreground_Green(StrengthenColor(FOREGROUND_GREEN))
	, Highlight_Color_Foreground_Purple(StrengthenColor(FOREGROUND_RED | FOREGROUND_BLUE))
	, Highlight_Color_Foreground_Cyan(StrengthenColor(FOREGROUND_GREEN | FOREGROUND_BLUE))
	, Highlight_Color_Foreground_Yellow(StrengthenColor(FOREGROUND_RED | FOREGROUND_GREEN))
{
	handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	c[1] = '\0';
}


ConsoleTools::~ConsoleTools()
{

}



void ConsoleTools::producePosList(
								const int produceQuantity,
								unsigned X,
								unsigned Y,
								unsigned width,
								unsigned height,
								unsigned int FlickerQuantity
								)

{
	char * c = NULL;
	for (int i = 0; i < produceQuantity; i++)
    {
        if (posListDataBase.size() >= produceQuantity)
        {
            break;
        }
        vector<COORD_char> * posList_b = new vector<COORD_char>();//need to delete

		while (posList_b->size() < FlickerQuantity)
		{
			//Fill container.
			AddUnrepititionCOOD(*posList_b,Random(X,X+width-1),Random(Y,Y+height-1));
		}

		
		for (vectorIt it = posList_b->begin();it != posList_b->end();it++)
		{
			//one by one output the single string on console,effect flicker.
			c = getSingleChar();
			it->str = c[0];
		}


        posListDataBase.push_back(posList_b);
    }
}



void ConsoleTools::countDown(int maxTime)
{
	COORD pos = {100,0};
	char c[20] = {0};

	for (int i = maxTime; i >= 0; i--)
	{
		WaitForSingleObject(semaphore_cursorWithCount, INFINITE);

		//Game count down.
		sprintf_s(c,20,"time : %d%s%s",i," "," ");
		writeText(c,pos,Color_Foreground_Purple);
		Sleep(1000);

		ReleaseSemaphore(semaphore_cursorWithCount, 1, NULL);
	}
	COORD_char cc = {NULL,'\0'};
	MatchStrs(cc);
}


const char * ConsoleTools::charToString(char cha)
{
	c[0] = cha;
	return c;
}


COORD ConsoleTools::getCurrentCursorPosition()
{
	//Get console information.
	GetConsoleScreenBufferInfo(handle_out,&consoleInformation);
	//Get console cursor position.
	COORD pos = {
					consoleInformation.dwCursorPosition.X,
					consoleInformation.dwCursorPosition.Y
				};
	return pos;
}


bool ConsoleTools::MatchStrs(COORD_char pos_char)
{
	static int count = 0;
	static COORD pos = {70,0};

	if (pos_char.str == '\0')
	{
		//When count down over will in this codes.
		countSelectedCorrect = 0;
		count = 0;
		pos.X = 70;
		return false;
	}
	

	if (selectedString[count] != pos_char.str)
	{
		return true;
	}

	writeText(charToString(selectedString[count]),pos,Highlight_Color_Foreground_Green);
	count++;
	pos.X++;

	if (count+1 > strlen(selectedString))
	{
		count = 0;
		pos.X = 70;
		return false;
	}

	return true;

}


void ConsoleTools::TopWriting()
{
	COORD position = {0,1};
	writeText("PS:press space to select,↑↓←→ Moving!",position,Highlight_Color_Foreground_Blue);

	COORD pos = {0,0};
	const char Str[] = "Please select words which is show above console to fill the string;";
	writeText(Str,pos,Highlight_Color_Foreground_Purple);

	pos.X += 68;
	writeText(">>",pos,Highlight_Color_Foreground_Blue);

	pos.X += 2;
	selectedString = strs[Random(0,16)];//Random output a string from baseData.
	writeText(selectedString,pos,Highlight_Color_Foreground_Yellow);//Write selected string

	int selectedStringLength = strlen(selectedString);
	pos.X += selectedStringLength;
	writeText("<<",pos,Highlight_Color_Foreground_Blue);

	pos.X = 100;
	pos.Y = 0;
	writeText("time : ... ",pos,Color_Foreground_Purple);

	pos.X += 15;
	char c[20] = {10};
	sprintf_s(c,20,"Quantity : %d ",countSelectedCorrect);
	writeText(c,pos,Color_Foreground_Purple);
}


void ConsoleTools::initCursorPosition(const short x,const short y)
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(handle_out,pos);
}


char * ConsoleTools::getSingleChar()
{
	static char str[2] = {Random(96,121),'\0'};//Static data just init once.
	if (str[0] < 122)
	{
		str[0]++;
		return str;
	}
	str[0] = 97;
	return str;
}


/*
value1~4:Output region on console.
value5:Output single string quantity.
*/
void ConsoleTools::mutipleStrFlicker()
{
	
	if (posList != NULL)
	{
		delete posList;
		posList = NULL;
	}
	
	
	posList = posListDataBase.front();
	posListDataBase.pop_front();
	for (vectorIt it = posList->begin();it != posList->end();it++)
	{
		singleStrFlicker(charToString(it->str),it->pos,30);
	}

	if (posListDataBase.size() <= 1)
	{
		ReleaseSemaphore(semaphore_producePosList, 1, NULL);
	}
}


int ConsoleTools::GetChar()
{
	int i = 0;
	do
	{
		/*
		If still have ASCII in the buffer after last get ASCII,
		keep running until the last one is got.
		*/
		i = _getch();
	} while (_kbhit());

	return i;
}


/*
Value_1:Windows width.
Value_2:Windows height.
*/
void ConsoleTools::setConsoleSize(int width,int height)
{
	char c[50] = {0};
	sprintf_s(c,50,"mode con cols=%d lines=%d",width,height);
	system(c);
}


/*
Value_1:Move step number.
*/
void ConsoleTools::cursorMoveRight(int runStep)
{
	COORD pos = getCurrentCursorPosition();

	pos.X += runStep;
	SetConsoleCursorPosition(handle_out,pos);
}


/*
Value_1:Move step number.
*/
void ConsoleTools::cursorMoveLeft(int runStep)
{
	cursorMoveRight(-runStep);
}


/*
Value_1:Move step number.
*/
void ConsoleTools::cursorMoveDown(int runStep)
{
	//Get console cursor position.
	COORD pos = getCurrentCursorPosition();

	pos.Y += runStep;
	
	SetConsoleCursorPosition(handle_out,pos);
}


/*
Value_1:Move step number.
*/
void ConsoleTools::cursorMoveUp(int runStep)
{
	cursorMoveDown(-runStep);
}


void ConsoleTools::cursorControl()
{
	int i = 0;
	COORD pos = {0};
	bool b = true;
	while (true)
	{
		i = GetChar();
		switch (i)
		{
		case MoveDown:
			cursorMoveDown(1);
			break;
		case MoveUp:
			cursorMoveUp(1);
			break;
		case MoveRight:
			cursorMoveRight(1);
			break;
		case MoveLeft:
			cursorMoveLeft(1);
			break;
		case Space:
			pos = getCurrentCursorPosition();
			for(vectorIt it = posList->begin() ; it != posList->end() ; it++)
			{
				if (pos.X == it->pos.X && pos.Y == it->pos.Y)
				{
					//If press space and this position have a word.
					b = MatchStrs(*it);
					break;
				}
			}

			if (!b)
			{
				countSelectedCorrect++;
				return;
			}
			break;
		default:
			break;
		}

	}
}


/*
value_1:String which will be output at console.
value_2:The position of write string.
value_3:String's attribute.
*/
void ConsoleTools::writeText(const char * str,COORD position,const WORD textAttribute)
{
	if (str == NULL)
	{
		return;
	}
	DWORD buf = 0;

	//Fill text attribute.
	FillConsoleOutputAttribute(handle_out,textAttribute,strlen(str),position,&buf);
	WriteConsoleOutputCharacter(handle_out,str,strlen(str),position,&buf);
}


void ConsoleTools::showKeyASCII()
{
	int i = 0;
	while (!_kbhit())
	{
		i = GetChar();
		cout<<i<<endl;
	}
}


/*
value1:String's position.
value2:String length.
value3:Move step number
*/
COORD ConsoleTools::textMoveDown(COORD position,int StringLength,int runStep)
{
	//Cut rectangle region.
	SMALL_RECT sr = {
						position.X,
						position.Y,
						TM_Width(position.X,StringLength),
						TM_Height(position.Y,1)
					};
	//Target region xy.
	COORD pos = {position.X,position.Y+runStep};

	//Fill character after cut.
	CHAR_INFO charInfo;
	charInfo.Attributes = getConsoleAttribute();

	//Move character.
	ScrollConsoleScreenBuffer(handle_out,&sr,NULL,pos,&charInfo);
	return pos;
}


/*
value1:String's position.
value2:String length.
value3:Move step number
*/
COORD ConsoleTools::textMoveUp(COORD position,int StringLength,int runStep)
{
	return textMoveDown(position,StringLength,-runStep);
	
}


/*
value1:String's position.
value2:String length.
value3:Move step number
*/
COORD ConsoleTools::textMoveRight(COORD position,int StringLength,int runStep)
{
	//Cut rectangle region.
	SMALL_RECT sr = {
						position.X,
						position.Y,
						TM_Width(position.X,StringLength),
						TM_Height(position.Y,1)
					};
	//Target region xy.
	COORD pos = {position.X+runStep,position.Y};

	//Fill character after cut.
	CHAR_INFO charInfo;
	charInfo.Attributes = getConsoleAttribute();

	//Move character.
	ScrollConsoleScreenBuffer(handle_out,&sr,NULL,pos,&charInfo);
	return pos;
}


/*
value1:String's position.
value2:String length.
value3:Move step number
*/
COORD ConsoleTools::textMoveLeft(COORD position,int StringLength,int runStep)
{
	return textMoveRight(position,StringLength,-runStep);
}


/*
value1:Strings to control.
value2:String's original position.
value3:The text attribute of strings.
*/
void ConsoleTools::textControl(const char * str,COORD initPosition,WORD textAttribute)
{
	if (str == NULL)
	{
		return;
	}

	//ready
	COORD pos = initPosition;
	writeText(str,pos,textAttribute);
	unsigned int stringLength = strlen((char *)str);
	int i = 0;

	while (!_kbhit())
	{
		i = GetChar();
		switch (i)
		{
		case MoveDown:
			pos = textMoveDown(pos,stringLength,1);
			break;
		case MoveUp:
			pos = textMoveUp(pos,stringLength,1);
			break;
		case MoveRight:
			pos = textMoveRight(pos,stringLength,1);
			break;
		case MoveLeft:
			pos = textMoveLeft(pos,stringLength,1);
			break;
		default:
			break;
		}
	}
}


WORD ConsoleTools::getConsoleAttribute()
{
	GetConsoleScreenBufferInfo(handle_out,&consoleInformation);
	return consoleInformation.wAttributes;
}


/*
value1:String.
value2:The position of flicker string.
value3:Flicker speed.
*/
void ConsoleTools::singleStrFlicker(const char * str,COORD stringPosition,unsigned speed)
{
	if (str == NULL)
	{
		return;
	}
	COORD pos = stringPosition;
	writeText(str,pos,Color_Background_Blue);
	Sleep(speed);
	writeText(str,pos,Highlight_Color_Foreground_Green);
}


bool ConsoleTools::AddUnrepititionCOOD(vector<COORD_char> & posList,int X,int Y)
{
	COORD_char pos_char;
	pos_char.pos.X = X;
	pos_char.pos.Y = Y;
	if (posList.size() == 0)
	{
		posList.push_back(pos_char);
		return true;
	}

	for (vectorIt it = posList.begin();it != posList.end();it++)
	{
		if (pos_char.pos.X == it->pos.X && pos_char.pos.Y == it->pos.Y)
		{
			//If exist the element in the vector contains,Exit the funtion.
			return false;
		}
	}

	posList.push_back(pos_char);
	return true;
}