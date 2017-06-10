// Decorator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Car
{
public :
	virtual void show() = 0;

};

/*ԭʼ������*/
class RunCar : public Car
{
public :
	void run()
	{
		cout << "run car" << endl;
	}
	virtual void show()
	{
		run();
	}
};

/*�̳�Car��ԭ���Ǳ��ֽӿڵ�һ��*/
class SwimCarDirector : public Car
{
public :
	SwimCarDirector(Car *p)
	{
		m_p = p;
	}

	/*���ֽӿ�һ��; ����ԭ���Ľӿ��������˷���*/
	virtual void show()
	{
		m_p->show();
		swim();
	}
private:
	Car *m_p;

private:
	/*������һ���µĽӿ�*/
	void swim()
	{
		cout << "can swim" << endl;
	}
};


class FlyCarDirector : public Car
{
public :
	FlyCarDirector(Car *p)
	{
		m_p = p;
	} 

	virtual void show()
	{
		m_p->show();
		fly();
	}

private:
	Car *m_p;

	/*������ǿ*/
	void fly()
	{
		cout << "can fly" << endl;
	}
};



int main(void)
{
	Car *runcar = NULL;
	runcar = new RunCar;
	runcar->show();

	cout << "---------" << endl;
	Car *swimCar = new SwimCarDirector(runcar);
	swimCar->show();


	cout << "---------" << endl;
	Car *flyCar = new FlyCarDirector(swimCar); //watch out
	flyCar->show();

	delete flyCar;
	delete swimCar;
	delete runcar;

    return 0;
}

