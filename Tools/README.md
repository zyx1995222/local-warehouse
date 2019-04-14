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

