# pragma once
# include "String.h"
# include "Map.h"


class __declspec(dllexport) Entrance
{
public:
	Entrance();
	Entrance(const String,const String);
	~Entrance();
	friend class HashMap;
private:
	String key;
	String value;
	Entrance* nextAddress;
};



class __declspec(dllexport) HashMap : public Map
{
public:
	HashMap();
	HashMap(HashMap&);
	~HashMap();
public:
	//base function
	bool put(String,String);
	String get(String);
	bool set(String,String);
	String remove(String);
public:
	int getLength();
	void list();
private:
	Entrance* FirstEntry;
	Entrance* LastEntry;
	int length;
};

