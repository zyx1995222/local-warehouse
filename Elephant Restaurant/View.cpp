# include "View.h"
# include "iostream"
using namespace std;

RestaurantView::RestaurantView()
{
	oNumber = 1000;
}

RestaurantView::~RestaurantView()
{

}

Order* RestaurantView::createFood()
{
	return orderFoods();
}

int RestaurantView::createView()
{
	cout<<
		"\n\n************************"
		<<
		"Welcome To Elephant Restaurant"
		<<
		"************************\n"
		<<
		endl;
	cout<<"You can choose a number below to finish what you want;\n"<<endl;

A:
	cout<<"\t1.Order"<<endl;
	cout<<"\t2.View Order"<<endl;
	cout<<"\t3.Exit System\n"<<endl;

	int i = 0;
	cout<<"Your Choice:";
	cin>>i;
	if (i == 1 || i==2 || i==3)
	{
		return i;
	}else
	{
		cout<<"\n---------------------\nError,Please input again;\n"<<endl;
		goto A;
	}
}

Order* RestaurantView::orderFoods()
{
	char foods[9][20] = {"��������",
		"�ͼ��𶹸�",
		"��������",
		"������",
		"ܽ��Ϻ",
		"Ҭ֭��������",
		"�������",
		"����ţ����",
		"������ΰ�"};
	int* foodss = new int(0);//�ڴ�û���ͷ�!!!!!
	int foodCount = 0;
	int i = 0;
	bool b = false;
	while (true)
	{
		cout<<"\n-----------------------"<<endl;
		cout<<"\nPlease choose the favorite foods by enter corresponding number.\n"<<endl;
		cout<<"1.��������\t4.������\t7.�������\n"<<endl;
		cout<<"2.�ͼ��𶹸�\t5.ܽ��Ϻ\t8.����ţ����\n"<<endl;
		cout<<"3.��������\t6.Ҭ֭��������\t9.������ΰ�\n"<<endl;
		b = false;
		cout<<"Your Choice(Enter '0' cancel choose):";
		cin>>i;
		if (i == 0)
		{
			if (foodCount == 0)
			{
				return NULL;
			}
			cout<<"\nHi,dear customer,below is your order's detail content.\n"<<endl;
			for (int i = 0; i < foodCount; i++)
			{
				cout<<"\t"<<i+1<<".\t"<<foods[foodss[i]-1]<<endl;
				cout<<endl;
			}
			int isConfirm = 0;
			bool bi = false;

C://����������������ʵ�ڲ���дwhileѭ���ˣ�����������ע�ͱ��(---1111---)

			cout<<"\n";
			cout<<"Please confirm the order(enter '1' confirm,'0' cancel):";
			cin>>isConfirm;
			bi = isBool(isConfirm);
			if (!bi)
			{
				goto C;//(---1111---)
			}
			if (isConfirm)
			{
				Order* order = new Order(++oNumber,foodss,foodCount);//�ڴ�û���ͷ�!(�Ѿ����)
				return order;
			}
			return NULL;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j+1 == i)
			{
				b = true;
				break;
			}else
			{
				continue;
			}
		}
		if (!b)
		{
			cout<<"Error,Please input again!!!"<<endl;
			int j = 0;
			bool d = false;
			while (!d)
			{
				cout<<"(Continue choose foods Enter '1','0' cancel):";
				cin>>j;
				d = isBool(j);
			}

			if (!j)
			{
				return NULL;
			}
			cout<<"\n";
			continue;
		}
		foodCount++;
		foodss = (int*)realloc(foodss,sizeof(int) * foodCount);
		foodss[foodCount-1] = i;
		cout<<"\n";
	}

}

bool RestaurantView::isBool(int i)
{
	if(i != 1 && i != 0)
	{
		cout<<"\nERROR!\n"<<endl;
		return false;
	}
	return true;
}

void RestaurantView::showOrder(int orderCount,Customer* customer)
{
	char foods[9][20] = {"��������",
		"�ͼ��𶹸�",
		"��������",
		"������",
		"ܽ��Ϻ",
		"Ҭ֭��������",
		"�������",
		"����ţ����",
		"������ΰ�"};
	int foodCount = 0;
	Order* order = NULL;
	cout<<"\n------------------------\n"<<endl;
	cout<<"Below is your all orders:\n"<<endl;
	for (int i = 0; i < orderCount; i++)
	{
		order = &((customer->getOrder())[i]);
		int n = order->getOrderNumber();
		cout<<n<<":"<<endl;
		
		foodCount = order->getFoodCount();
		for (int j = 0; j < foodCount; j++)
		{
			int a = (order->getFood())[j];
			cout<<"\t"<<j+1<<".\t"<<foods[a-1]<<"\n\n"<<endl;
		}
	}
}