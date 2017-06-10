// AbstractFactory.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fruit
{
	public :
	virtual void getName()
	{
		cout << "fruit\n";
	}
};


//�Ϸ��㽶
class SouthBanana : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "South Banana " << endl;
	}
};


/*�Ϸ�ƻ��*/
class SouthApple : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "South Apple " << endl;

	}
};


/*�����㽶*/
class NorthBanana : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "North Banana " << endl;
	}
};


/*����ƻ��*/
class NorthApple : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "North Apple " << endl;
	}
};

/*���󹤳�*/
class FruitFactory
{
public:
	virtual Fruit* getApple()
	{
		return new Fruit();
	}

	virtual Fruit* getBanana()
	{
		return new Fruit();
	}
};


/*��������1*/
class SourthFruitFactory : public FruitFactory
{
	public :
	virtual Fruit* getApple()
	{
		return new SouthApple();
	} 
	
	virtual Fruit* getBanana()
	{
		return new SouthBanana();
	}
};


/*��������2*/
class NorthFruitFactory : public FruitFactory
{
public :
	virtual Fruit* getApple()
	{
		return new NorthApple();
	}

	virtual Fruit* getBanana()
	{
		return new NorthBanana();
	}
};



int main()
{

	cout << "---Main Function Begin---" << endl;

	FruitFactory *ff = NULL;
	Fruit *fruit = NULL;

	ff = new SourthFruitFactory();
	fruit = ff->getApple();
	fruit->getName();
	fruit = ff->getBanana();
	fruit->getName();
	delete fruit;
	delete ff;


	ff = new NorthFruitFactory();
	fruit = ff->getApple();
	fruit->getName();
	fruit = ff->getBanana();
	fruit->getName();
	delete fruit;
	delete ff;

	cout << "---Main Function End---" << endl;

    return 0;
}

