# pragma once

/*
A simple stack container for store static data type.
*/

//Container prototype
typedef struct
{
	int stackLength;//Container length.
	int stackElementNumber;//Current element quantity in container.
	int ElemTypeLen;//The type size of each element in the container.
	void * Elements;//Stack container.
}Stack;

void stackNew(Stack * stack,int ElemTypeLen);//Create stack.
void stackDispose(Stack * stack);//Destroy stack.
void stackPush(Stack * stack,void * value);//Add a element for stack.
void stackPop(Stack * stack,void * returnValue);//Popup a element from stack.
static void stackGrow(Stack * stack);//The Internal function is for increase stack length when stack element quantity will beyond the previous length.

//To show stack elemnt on console.
template<typename T>
void show(Stack * stack)
{
	T * a = (T *)stack->Elements;
	for (int i = 0; i < stack->stackElementNumber; i++)
	{
		cout<<a[i]<<endl;
	}
}