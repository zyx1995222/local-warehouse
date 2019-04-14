Tools
======
## String

**Include the head file and simple use.**<br><br>
Simple example
```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{
	String s = "hello world";
	cout<<s<<endl;
	system("pause");
}
```
or

```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{

	String s1("hello world");
	String s2 = String("hello world");
	String* s3 = new String("hello world");
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<*s3<<endl;
	delete s3;
	system("pause");
}
```
*Note:The String class just support a kind of output way is "cout".*

The assignment

```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{
	String s = "Hello world";
	String s1 = "Hi";
	String s2 = s;
	s = s1;
	s1 = "Hello"
	cout<<s<<endl;
	cout<<s1<<endl;
	cout<<s2<<endl;
	system("pause");
}
```
You can let the value equal NULL.

`
String s = NULL;
`

You can create String class with char array length.

```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{
	String s(100);
	s = "hello hello";
	cout<<s<<endl;
	system("pause");
}
```

Input a string to assign for a String variabel by using "cin".

*note:The string  you input length can not beyond the length of String variable.*

```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{
	String s(200);
	cin>>s;
	cout<<s<<endl;
	system("pause");
}
```

Condition judge.

```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{
	String s = "ABC";
	if (s == "ABC")
	{
		cout<<"Yes"<<endl;
	}
	
	if(s != "ABc")
	{
		cout<<"Yes"<<endl;
	}

	

	system("pause");
}
```

```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{
	String s = "ABC";
	String s1 = "ABC";
	String s2 = "ABc";

	if (s == s1)
	{
		cout<<"Yes"<<endl;
	}

	if (s != s2)
	{
		cout<<"Yes"<<endl;
	}

	system("pause");
}
```

Judge if the String variable is equal NULL.

```
# include "iostream"
# include "String.h"
using namespace std;

void main()
{
	String s(10);
	s = NULL;

	if (s == NULL)
	{
		cout<<"Yes"<<endl;
	}

	if (s != NULL)
	{
		cout<<"Yes"<<endl;
	}
	system("pause");
}
```
