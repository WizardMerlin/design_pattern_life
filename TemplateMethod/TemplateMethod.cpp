// TemplateMethod.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class MakeCar
{
protected :
	virtual void makeHead() = 0;
	virtual void makeBody() = 0;
	virtual void makeTail() = 0;


public: 
	void make()
	{
		makeHead(); //把相关步骤全部抽象出来
		makeBody();
		makeTail();
	}

};

/*其中一种算法实现*/
class MakeBus : public MakeCar
{
	/*make方法不用重写*/
protected :
	virtual void makeHead()
	{
		cout << "bus 组装 车头" << endl;
	} 
	
	virtual void makeBody()
	{
		cout << "bus 组装 车身" << endl;
	}
	
	virtual void makeTail()
	{
		cout << "bus 组装 车尾" << endl;
	}

};

class MakeJeep : public MakeCar
{
protected :
	
	virtual void makeHead()
	{
		cout << "Jeep 组装 车头" << endl;
	} 
	
	virtual void makeBody()
	{
		cout << "Jeep 组装 车身" << endl;
	} 
	
	virtual void makeTail()
	{
		cout << "Jeep 组装 车尾" << endl;
	}

};


int main()
{

	MakeCar *bus = new MakeBus;
	bus->make();

	MakeCar *jeep = new MakeJeep;
	jeep->make();

	delete bus;
	delete jeep;

    return 0;
}

