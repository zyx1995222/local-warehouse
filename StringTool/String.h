#pragma once

/*
A tool class used to simplify string operate.
Date code : 2019/3/26.
author : React.
*/
class __declspec(dllexport) String
{
public:
	//constractors
	String();
	String(const int);
	String(const char*);
	String(String&);
	~String();
public:
	//Used for output.
	void printF();
public:
	//operator overloading
	void operator=(const char*);
	void operator=(const String&);
	bool operator==(const char*);
	bool operator==(const String&);
	bool operator!=(const char*);
	bool operator!=(const String&);
	String operator+(String&);
	String operator+(char*);
public:
	char* getString();
	int getLength();
private:
	//Array of character and its length.
	char* string;
	int length;
};

//operator overloading
__declspec(dllexport) std::ostream& operator<<(std::ostream &,String&);
__declspec(dllexport) void operator>>(std::istream&,String&);
__declspec(dllexport) String operator+(char*,String&);



