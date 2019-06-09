# include "iostream"
# include "Function.h"
# include "assert.h"
using namespace std;


void stackNew(Stack * stack,int ElemTypeLen)
{
	assert(stack);

	stack->stackLength = 4;
	stack->stackElementNumber = 0;
	stack->ElemTypeLen = ElemTypeLen;
	stack->Elements = NULL;
	stack->Elements = malloc(stack->stackLength * ElemTypeLen);

	assert(stack);

	memset(stack->Elements,0,stack->stackLength * ElemTypeLen);
}

void stackDispose(Stack * stack)
{
	assert(stack);

	free(stack->Elements);
	stack->Elements = NULL;
}

void stackPush(Stack * stack,void * value)
{
	assert(stack);
	assert(value);

	if (stack->stackElementNumber == stack->stackLength)
	{
		stackGrow(stack);
	}
	
	char * cValue = (char *)value;
	char * cElement = (char *)stack->Elements;
	char * target = cElement + stack->stackElementNumber * stack->ElemTypeLen;

	memcpy(target,cValue,stack->ElemTypeLen);

	stack->stackElementNumber++;
}

void stackPop(Stack * stack,void * returnValue)
{
	assert(stack);
	assert(returnValue);
	assert(stack->stackLength > 0);

	char * target = (char *)returnValue;
	char * cElements = (char *)stack->Elements;
	char * source = cElements + (stack->stackElementNumber-1) * stack->ElemTypeLen;

	memcpy(target,source,stack->ElemTypeLen);

	stack->stackElementNumber--; 
}

static void stackGrow(Stack * stack)
{
	stack->stackLength = stack->stackLength * 2;
	stack->Elements = realloc(stack->Elements,stack->stackLength * stack->ElemTypeLen);
}

