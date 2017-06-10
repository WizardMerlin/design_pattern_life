// TemplateMethod.cpp : �������̨Ӧ�ó������ڵ㡣
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
		makeHead(); //����ز���ȫ���������
		makeBody();
		makeTail();
	}

};

/*����һ���㷨ʵ��*/
class MakeBus : public MakeCar
{
	/*make����������д*/
protected :
	virtual void makeHead()
	{
		cout << "bus ��װ ��ͷ" << endl;
	} 
	
	virtual void makeBody()
	{
		cout << "bus ��װ ����" << endl;
	}
	
	virtual void makeTail()
	{
		cout << "bus ��װ ��β" << endl;
	}

};

class MakeJeep : public MakeCar
{
protected :
	
	virtual void makeHead()
	{
		cout << "Jeep ��װ ��ͷ" << endl;
	} 
	
	virtual void makeBody()
	{
		cout << "Jeep ��װ ����" << endl;
	} 
	
	virtual void makeTail()
	{
		cout << "Jeep ��װ ��β" << endl;
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

