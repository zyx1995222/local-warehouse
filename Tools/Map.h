# pragma once
# include "String.h"

/*
	Map map = new HashMap();
	map.put("key","value");
	map.get("key");
	map.set("key");
	map.remove("key");
	
*/


class __declspec(dllexport) Map
{
public:
	virtual ~Map();
public:
	virtual bool put(String,String) = 0;
	virtual String get(String) = 0;
	virtual bool set(String,String) = 0;
	virtual String remove(String) = 0;
	virtual int getLength() = 0;
	virtual void list() = 0;
};



