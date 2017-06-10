// State.cpp : 定义控制台应用程序的入口点。
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

/*传入Worder然后判断状态给出动作, 不满足该动作的行为, 直接跳转到下一个行为*/
class State1 : public State
{
public:
	virtual void doSomeThing(Worder *w); // Worder有一个事件属性作为状态判断的依据
};


class State2 : public State
{
public:
	virtual void doSomeThing(Worder *w);
};



/*根据自己内部条件m_hour选择不同的状态逻辑(状态类)*/
class Worder
{
private:
	int m_hour;

	State *m_currentstate;

public :
	Worder() 
	{
		cout << "默认状态1" << endl;
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
		cout << "当前状态1:  eat breakfast" << endl;
	}
	else
	{
		delete w->getState(); //状态 1 不满足 要转到状态 2
		w->setState(new State2);
		w->getState()->doSomeThing(w);
	}
}


void State2::doSomeThing(Worder *w)
{
	if (w->getHour() == 9 || w->getHour() == 10) //状态 2 不满足 要转到状态 3 .
	{
		cout << "当前状态2:  work " << endl;
	}
	else
	{
		delete w->getState();
		w->setState(new State1); //恢复到当初状态
		cout << "当前时间点： " << m_hour << "未知状态" << endl;
	}
}


int main(void)
{
	Worder *w1 = new Worder; //默认状态1


	w1->changestate(7);
	w1->doSomeThing();//直接调用了当前状态类的相关逻辑(其内部会根据当前条件进行状态调整)

	w1->changestate(10);
	w1->doSomeThing();

	delete w1;

    return 0;
}

