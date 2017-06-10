// Mediator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Mediator;

class Person2
{
public :
	Person2(string name, int sex, int condition, Mediator *m)
	{
		m_name = name;
		m_sex = sex;
		m_condition = condition;
		m_m = m;
	} 
	
	string getName()
	{
		return m_name;
	} 
	
	int getSex()
	{
		return m_sex;
	} 
	
	int getCondit()
	{
		return m_condition;
	} 
	
	Mediator *getMediator()
	{
		return m_m;
	}

	virtual void getParter(Person2 *p) = 0;

protected:
	string m_name; //
	int m_sex; //1 男 2 女
	int m_condition; //123456789;

	Mediator *m_m;
};
class Mediator
{
public :
	Mediator()
	{
		pMan = NULL;
		pWoman = NULL;
	} 
	
	void setWoman(Person2 *p)
	{
		pWoman = p;
	} 
	
	void setMan(Person2 *p)
	{
		pMan = p;
	} 
	
	void getPartner()
	{
		if (pMan->getSex() == pWoman->getSex())
		{
			cout << "No No No 我不是同性恋" << endl;
		} 
		if(pMan->getCondit() == pWoman->getCondit())
		{
			cout << pMan->getName() << " 和 " << pWoman->getName() << "绝配" << endl;
		}
		else
		{
			cout << pMan->getName() << " 和 " << pWoman->getName() << "不配" << endl;
		}
	}

private:
	Person2 *pMan;
	Person2 *pWoman;
};


class Woman2 : public Person2
{
public :
	Woman2(string name, int sex, int condition, Mediator *m) : Person2(name, sex, condition,m)
	{
		;
	} 
	
	virtual void getParter(Person2 *p)
	{
		/*设置Mediator类中的男女*/
		this->getMediator()->setWoman(this);
		this->getMediator()->setMan(p);

		this->getMediator()->getPartner();
	}

};


class Man2 : public Person2
{
public :
	Man2(string name, int sex, int condition, Mediator *m) : Person2(name, sex, condition, m)
	{
	} 
	
	virtual void getParter(Person2 *p)
	{
		this->getMediator()->setMan(this);
		this->getMediator()->setWoman(p);

		this->getMediator()->getPartner();
	}

};


int main()
{

	Mediator *mediator = new Mediator;
	Woman2 *w1 = new Woman2("小芳", 2, 4, mediator);
	Man2 *m1 = new Man2("张三", 1, 3, mediator);
	Man2 *m2 = new Man2("李四", 1, 4, mediator);

	w1->getParter(m1);
	w1->getParter(m2);

	delete w1;
	delete m1;
	delete m2;
	delete mediator;

    return 0;
}

