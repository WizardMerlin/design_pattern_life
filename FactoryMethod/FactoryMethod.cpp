// FactoryMethod.cpp : 定义控制台应用程序的入口点。
//
// 工厂模式 (改进SimpleFactory中的水果创建模型)


#include <iostream>

using namespace std;

class Fruit
{
	public :
	virtual void getName()
	{
		cout << "fruit" << endl;
	}
};

class Banana : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "Banana " << endl;
	}
};

/*抽象工厂*/
class FruitFactory
{
	public :
	virtual Fruit* getFruit()
	{
		return new Fruit();
	}
};

/*具体的工厂*/
class BananaFactory : public FruitFactory
{
	public :
	virtual Fruit* getFruit()
	{
		return new Banana;
	}
};


/*下面再扩展一个产品, 那么需要扩展两个东西: 相关产品, 相关工厂*/
class Apple : public Fruit
{
	public:
	virtual void getName()
	{
		cout << "Apple" << endl;
	}
};

class AppleFactory : public FruitFactory
{
	public :
	virtual Fruit* getFruit()
	{
		return new Apple;
	}
};


int main(void) 
{
	FruitFactory * factory = NULL;
	Fruit *fruit = NULL;
	/*1. 先创建先关的具体工厂实例(从而创建相关的具体产品)*/
	factory = new BananaFactory();
	fruit = factory->getFruit();
	fruit->getName();
	delete fruit;
	fruit = NULL;
	delete factory;
	factory = NULL;

	cout << "--------------" << endl;
	/*2. 再创建一个产品的时候, 还是需要创建和产品相关的工厂*/
	factory = new AppleFactory();
	fruit = factory->getFruit();
	fruit->getName();

	delete fruit;
	fruit = NULL;
	delete factory;
	factory = NULL;


	return 0;
}