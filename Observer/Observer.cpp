// Observer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

#include <vector>
#include <string>

using namespace std;


class Secretary;

class PlayserObserver
{
public :
	PlayserObserver(string name)
	{
		m_name = name;
	}

	void update(string action)
	{
		cout << "观察者 "<< m_name <<"收到 action : " << action << endl;
	}
private:
	string m_name;
};


class Secretary
{
public :
	void addObserver(PlayserObserver *o)
	{
		v.push_back(o);
	}

	void Notify(string action)
	{
		for (vector<PlayserObserver *>::iterator it = v.begin(); it != v.end(); it++)
		{
			(*it)->update(action);
		}
	} 
	
	void setAction(string action)
	{
		m_action = action;
		Notify(m_action);
	}
private:
	string m_action;
	vector<PlayserObserver *> v;
};


int main()
{

	Secretary *s1 = new Secretary; //被观察者

	PlayserObserver *po1 = new PlayserObserver("小张");
	PlayserObserver *po2 = new PlayserObserver("小李");

	s1->addObserver(po1);
	s1->addObserver(po2);

	//事件发生然后通知
	s1->setAction("老板来了");
	s1->setAction("老板走了");

	return 0;
}



