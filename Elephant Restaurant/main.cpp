# include "iostream"
# include "View.h"
# include "Order.h"
# include "Customer.h"
using namespace std;

/*
The demo is for pratice about c++;
A restaurant name elephant.
Maybe have many bug,please feedback to me.(E-mail:710812984@qq.com)
Date code : 2019/3/24.
*/




void main()
{

	RestaurantView rw;
	Order* order = NULL;
	int orderCount = 0;
	Customer* customer = new Customer();//内存泄漏
	int customerChoice = 0;

B://记住这个位置，下面程序会疯狂回头来这里的！！！！！看注释标号(---2222---)

	customerChoice  = rw.createView();
	if (customerChoice == 3)
	{
		cout<<"\nThanks use elephant restaurant manage system.\n"<<endl;
		system("pause");
		return;
	}
	if (customerChoice == 1)
	{
		order = rw.createFood();
		if (order == NULL)
		{
			goto B;//(---2222---)
		}
		cout<<"\nThe order is generated , Please wait..\n"<<endl;
		orderCount++;
		Order* or = customer->getOrder();
		if (or == NULL)
		{
			or = new Order();//内存泄漏
			*or = *order;
		}else
		{
			or = (Order*)realloc(or,sizeof(Order) * orderCount);
			or[orderCount-1] = *order;
		}
		customer->setOrder(or);
		//cout<<(customer->getOrder())[orderCount-1].getOrderNumber()<<endl;
		delete order;
		goto B;//(---2222---)
	}
	if (customerChoice == 2)
	{
		if (orderCount == 0)//我不想的.
		{
			int i1 = 0;
			cout<<"You have not placed order yet."<<endl;
			cout<<"(goto order:'1'   Exit System:'0'):";
			cin>>i1;
			if (!rw.isBool(i1))
			{
				goto B;//(---2222---)
			}
			if (i1 == 0)
			{
				cout<<"\nThanks use elephant restaurant manage system.\n"<<endl;
				system("pause");
				return;
			}
			goto B;//(---2222---)
		}
		rw.showOrder(orderCount,customer);
		system("pause");
		goto B;//(---2222---)
	}



	system("pause");
}








/*
code run result : 

-----------------------------------------------------------


************************Welcome To Elephant Restaurant************************

You can choose a number below to finish what you want;

        1.Order
        2.View Order
        3.Exit System

Your Choice:3

Thanks use elephant restaurant manage system.

请按任意键继续. . .

-----------------------------------------------------------
*/