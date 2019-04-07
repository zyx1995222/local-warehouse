# include "iostream"
# include "String.h"
# include "HashMap.h"
using namespace std;

HashMap::HashMap()
{
	length = 0;
}

HashMap::HashMap(HashMap &HM)
{
	length = 0;
	Entrance* e = HM.FirstEntry;
	while(true)
	{
		put(e->key,e->value);
		e = e->nextAddress;
		if (e == NULL)
		{
			break;
		}
	}
}

HashMap::~HashMap()
{
	if (length == 0)
	{
		return;
	}

	//Free Entrance memory.
	Entrance* e = FirstEntry;
	Entrance* ee = NULL;
	while (true)
	{
		
		ee = e;
		e = e->nextAddress;
		delete ee;
		ee = NULL;
		if (e == NULL)
		{
			break;
		}
	}
}

bool HashMap::put(String key,String value)
{
	if (key == NULL)
	{
		return false;
	}

	if (length == 0)
	{
		//The first object is created by new.
		//First object will remember the last object and the last object's attribute "nextAddress" is NULL.
		//First object just is last object.
		FirstEntry = new Entrance(key,value);//ÄÚ´æÐ¹Â©.
		FirstEntry->nextAddress = NULL;
		LastEntry = FirstEntry;
		length++;
		return true;
	}


	{
		//Can not exist same key.
		Entrance* e = FirstEntry;
		while(true)
		{
			if (e->key == key)
			{
				return false;
			}
			e = e->nextAddress;
			if (e == NULL)
			{
				break;
			}
		}
	}


	//A new object is created by new.
	//Object LastEntry's attribute "nextAddress" will remember the address of the new object.
	//New object become the object LastEntry.
	Entrance* newEntry = new Entrance(key,value);//ÄÚ´æÐ¹Â©.
	LastEntry->nextAddress = newEntry;
	LastEntry = newEntry;
	LastEntry->nextAddress = NULL;
	length++;
	return true;
}

String HashMap::get(String key)
{
	//Get the value by key sent.
	if (key == NULL)
	{
		return NULL;
	}
	Entrance* e = FirstEntry;
	while(true)
	{
		if (e->key == key)
		{
			return e->value;
		}
		e = e->nextAddress;
		if (e == NULL)
		{
			break;
		}
	}
	return NULL;
}

bool HashMap::set(String key,String value)
{
	//Update the value by key sent;
	if (key == NULL)
	{
		return false;
	}

	Entrance* e = FirstEntry;
	while(true)
	{
		if (e->key == key)
		{
			e->value = value;
			return true;
		}
		e = e->nextAddress;
		if (e == NULL)
		{
			break;
		}
	}
	return false;
}

String HashMap::remove(String key)
{

	if (key == NULL)
	{
		return NULL;
	}

	String removedString = NULL;

	//If the key sent equals the FirstEntry's key,will handle alone.
	if (FirstEntry->key == key)
	{
		Entrance* BufferFirstEntry = FirstEntry;
		FirstEntry = FirstEntry->nextAddress;
		length--;
		removedString = BufferFirstEntry->value;
		delete BufferFirstEntry;
		BufferFirstEntry = NULL;
		return removedString;
	}

	/*
	Let the object in front of the target object remenber the address
	after the target object to implement the effect for remove the object.
	*/
	Entrance* e = FirstEntry;
	Entrance* eBefore = NULL;
	while(true)
	{
		if (e->key == key)
		{
			eBefore->nextAddress = e->nextAddress;
			length--;
			String removedString = e->value;
			delete e;
			e = NULL;
			return removedString;
		}
		eBefore = e;
		e = e->nextAddress;
		if (e == NULL)
		{
			break;
		}
	}

	return NULL;
}

int HashMap::getLength()
{
	return length;
}

void HashMap::list()
{
	//Display all key and value;
	if (length == 0)
	{
		cout<<"NO VALUE."<<endl;
		return;
	}
	Entrance* e = FirstEntry;
	String key = NULL;
	String value = NULL;
	while (true)
	{
		key = e->key;
		value = e->value;
		cout<<key<<"---"<<value<<endl;
		e = e->nextAddress;
		if (e == NULL)
		{
			break;
		}
	}
}


//------------------------------------------------------------

Entrance::Entrance()
{
}

Entrance::Entrance(const String key,const String value)
{
	this->key = key;
	this->value = value;
}

Entrance::~Entrance()
{

}