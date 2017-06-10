// State.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Worder;

class State
{
public :
	virtual void doSomeThing(Worder *w) = 0;
protected:
	int m_hour;
};

/*����WorderȻ���ж�״̬��������, ������ö�������Ϊ, ֱ����ת����һ����Ϊ*/
class State1 : public State
{
public:
	virtual void doSomeThing(Worder *w); // Worder��һ���¼�������Ϊ״̬�жϵ�����
};


class State2 : public State
{
public:
	virtual void doSomeThing(Worder *w);
};



/*�����Լ��ڲ�����m_hourѡ��ͬ��״̬�߼�(״̬��)*/
class Worder
{
private:
	int m_hour;

	State *m_currentstate;

public :
	Worder() 
	{
		cout << "Ĭ��״̬1" << endl;
		m_currentstate = new State1;
	}

	/*setHour()*/
	void changestate(int hour)
	{
		m_hour = hour;
	} 
	
	int getHour()
	{
		return m_hour;
	} 
	
	void setState(State *s)
	{
		m_currentstate = s;
	} 
	
	State * getState()
	{
		return m_currentstate;
	} 
	
	void doSomeThing()
	{
		m_currentstate->doSomeThing(this); 
	}

};

void State1::doSomeThing(Worder *w)
{
	if (w->getHour() == 7 || w->getHour() == 8)
	{
		cout << "��ǰ״̬1:  eat breakfast" << endl;
	}
	else
	{
		delete w->getState(); //״̬ 1 ������ Ҫת��״̬ 2
		w->setState(new State2);
		w->getState()->doSomeThing(w);
	}
}


void State2::doSomeThing(Worder *w)
{
	if (w->getHour() == 9 || w->getHour() == 10) //״̬ 2 ������ Ҫת��״̬ 3 .
	{
		cout << "��ǰ״̬2:  work " << endl;
	}
	else
	{
		delete w->getState();
		w->setState(new State1); //�ָ�������״̬
		cout << "��ǰʱ��㣺 " << m_hour << "δ֪״̬" << endl;
	}
}


int main(void)
{
	Worder *w1 = new Worder; //Ĭ��״̬1


	w1->changestate(7);
	w1->doSomeThing();//ֱ�ӵ����˵�ǰ״̬�������߼�(���ڲ�����ݵ�ǰ��������״̬����)

	w1->changestate(10);
	w1->doSomeThing();

	delete w1;

    return 0;
}

