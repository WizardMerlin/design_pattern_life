// SimpleFactory.cpp : �������̨Ӧ�ó������ڵ㡣
//

//
/*�򵥹���ģʽ*/
#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;

};


class Banana : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "banana" << endl;
	}

};


class Pear : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "pear" << endl;
	}

};


class Factory
{
public:
	static Fruit* Create(char *name)
	{
		Fruit *tmp = NULL;
		if (strcmp(name, "pear") == 0)
		{
			tmp = new Pear();
		}
		else if (strcmp(name, "banana") == 0)
		{
			tmp = new Banana();
		}

		return tmp;
	}
};


int main()
{
	Fruit *pear = Factory::Create("pear");
	if (pear == NULL)
	{
		cout << "������Ʒʧ��\n";
	}
	pear->getFruit();
	Fruit *banana = Factory::Create("banana");
	banana->getFruit();

	return 0;
}



