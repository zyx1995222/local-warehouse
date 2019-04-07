# include "iostream"
# include "String.h"
using namespace std;

String::String()
{
	length = 0;
	this->string = new char[length+1];
	strcpy_s(this->string,length+1,"");
}

String::String(const int leng)
{
	
	length = leng;
	this->string = new char[length+1];
	strcpy_s(this->string,length+1,"");
}

String::String(const char* string)
{
	if (string == NULL)
	{

		length = 0;
		this->string = new char[length+1];
		strcpy_s(this->string,length+1,"");
		return;
	}
	length = strlen(string);
	this->string = new char[length+1];
	strcpy_s(this->string,length+1,string);

}

String::String(String &string)
{
	if (string == NULL)
	{
		length = 0;
		this->string = new char[length+1];
		strcpy_s(this->string,length+1,"");
		return;
	}
	this->length = string.length;
	this->string = new char[this->length + 1];
	strcpy_s(this->string,length + 1,string.string);

}

String::~String()
{
	if (string != NULL)
	{
		delete[] string;
		string = NULL;
	}
}

void String::printF()
{
	cout<<string<<"----"<<length<<endl;
}

void String::operator=(const char* str)
{
	if (str == NULL)
	{
		length = 0;
		this->string = new char[length+1];
		strcpy_s(this->string,length+1,"");
		return;
	}
	delete[] string;
	length = strlen(str);
	string = new char[length+1];
	strcpy_s(string,length+1,str);
}

void String::operator=(const String &str)
{
	delete[] string;
	length = str.length;
	string = new char[length+1];
	strcpy_s(string,length+1,str.string);
}

char* String::getString()
{
	return string;
}

int String::getLength()
{
	return length;
}

bool String::operator==(const char* str)
{
	if (str == NULL)
	{
		if (length == 0)
		{
			return true;
		}
		return false;
	}



	if (length == strlen(str) + 1)
	{
		int isSame = strcmp(string,str);
		if (!isSame)
		{
			return true;
		}
		return false;
	}else
	{
		return false;
	}
}

bool String::operator==(const String &str)
{
	if (length == str.length)
	{
		int isSame = strcmp(string,str.string);
		if (!isSame)
		{
			return true;
		}
		return false;
	}else
	{
		return false;
	}
	
}

bool String::operator!=(const char* str)
{
	return !(*this == str);
	
}

bool String::operator!=(const String& str)
{
	return !(*this == str);
}

String String::operator+(String &str)
{
	char* c = new char[length + str.length + 10];

	strcpy_s(c,length+1,string);
	strcat_s(c,length + str.length + 10,str.string);

	String s = c;

	delete[] c;
	c = NULL;
	return s;
}

String String::operator+(char* str)
{
	char* c = new char[length + strlen(str) + 10];

	strcpy_s(c,length+1,string);
	strcat_s(c,length + strlen(str) + 10,str);

	String s = c;

	delete[] c;
	c = NULL;
	return s;
}

//---------------------------------------------------------------

std::ostream& operator<<(std::ostream &out,String &s)
{
	out << s.getString();
	return out;
}

void operator>>(std::istream &in,String &s)
{
	in>>s.getString();
}

String operator+(char* str1,String& str2)
{
	char* c = new char[strlen(str1)+str2.getLength()+10];
	memset(c,0,strlen(str1)+str2.getLength()+10);
	strcpy_s(c,strlen(str1)+1,str1);
	
	strcat_s(c,strlen(str1)+str2.getLength()+10,str2.getString());
	String s = c;

	delete[] c;
	c = NULL;
	return s;
}




