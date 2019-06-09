# include "iostream"
# include "Function.h"
using namespace std;


int main(void)
{
	
	Stack stack;
	stackNew(&stack,sizeof(double));
	double a = 0.5;

	for (int i = 0; i < 200; i++)
	{
		stackPush(&stack,&a);
		a = a + 0.5;
	}
	show<double>(&stack);

	cout<<"-------------"<<endl;

	for (int i = 0; i < 50; i++)
	{
		stackPop(&stack,&a);
		cout<<a<<endl;
	}

	

	


	cout<<"HelloWorld"<<endl;
	system("pause");
	return 0;
}