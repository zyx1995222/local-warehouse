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
	length = strlen(string)+1;
	this->string = new char[length];
	strcpy_s(this->string,length,string);

}

String::String(const String &string)
{
	this->length = string.length;
	this->string = new char[this->length];
	strcpy_s(this->string,length,string.string);

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
	length = strlen(str) + 1;
	string = new char[length];
	strcpy_s(string,length,str);
}

void String::operator=(const String &str)
{
	delete[] string;
	length = str.length;
	string = new char[length];
	strcpy_s(string,length,str.string);
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

std::ostream& operator<<(std::ostream &out,String &s)
{
	out << s.getString();
	return out;
}

void operator>>(std::istream &in,String &s)
{
	in>>s.getString();
}




