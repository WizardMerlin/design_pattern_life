// FactoryMethod.cpp : �������̨Ӧ�ó������ڵ㡣
//
// ����ģʽ (�Ľ�SimpleFactory�е�ˮ������ģ��)


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

/*���󹤳�*/
class FruitFactory
{
	public :
	virtual Fruit* getFruit()
	{
		return new Fruit();
	}
};

/*����Ĺ���*/
class BananaFactory : public FruitFactory
{
	public :
	virtual Fruit* getFruit()
	{
		return new Banana;
	}
};


/*��������չһ����Ʒ, ��ô��Ҫ��չ��������: ��ز�Ʒ, ��ع���*/
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
	/*1. �ȴ����ȹصľ��幤��ʵ��(�Ӷ�������صľ����Ʒ)*/
	factory = new BananaFactory();
	fruit = factory->getFruit();
	fruit->getName();
	delete fruit;
	fruit = NULL;
	delete factory;
	factory = NULL;

	cout << "--------------" << endl;
	/*2. �ٴ���һ����Ʒ��ʱ��, ������Ҫ�����Ͳ�Ʒ��صĹ���*/
	factory = new AppleFactory();
	fruit = factory->getFruit();
	fruit->getName();

	delete fruit;
	fruit = NULL;
	delete factory;
	factory = NULL;


	return 0;
}