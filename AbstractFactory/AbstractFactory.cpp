// AbstractFactory.cpp : 定义控制台应用程序的入口点。
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


//南方香蕉
class SouthBanana : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "South Banana " << endl;
	}
};


/*南方苹果*/
class SouthApple : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "South Apple " << endl;

	}
};


/*北方香蕉*/
class NorthBanana : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "North Banana " << endl;
	}
};


/*北方苹果*/
class NorthApple : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "North Apple " << endl;
	}
};

/*抽象工厂*/
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


/*工厂子类1*/
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


/*工厂子类2*/
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

