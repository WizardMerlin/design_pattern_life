// Observer.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "�۲��� "<< m_name <<"�յ� action : " << action << endl;
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

	Secretary *s1 = new Secretary; //���۲���

	PlayserObserver *po1 = new PlayserObserver("С��");
	PlayserObserver *po2 = new PlayserObserver("С��");

	s1->addObserver(po1);
	s1->addObserver(po2);

	//�¼�����Ȼ��֪ͨ
	s1->setAction("�ϰ�����");
	s1->setAction("�ϰ�����");

	return 0;
}



