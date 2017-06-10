// Command.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;


class Vendor
{
public :
	void sailbanana()
	{
		cout << "���㽶" << endl;
	} 
	
	void sailapple()
	{
		cout << "��ƻ��" << endl;
	}
};


class Command
{
public :
	virtual void sail() = 0;
};

/*��װ�ľ������1*/
class BananaCommand : public Command
{
public :
	BananaCommand(Vendor *v)
	{
		m_v = v;
	} 
	
	Vendor *getV(Vendor *v)
	{
		return m_v;
	}
	void setV(Vendor *v)
	{
		m_v = v;
	} 
	
	virtual void sail()
	{
		m_v->sailbanana();
	}

private:
	Vendor *m_v;
};

/*��װ�ľ������2*/
class AppleCommand : public Command
{
public :
	AppleCommand(Vendor *v)
	{
		m_v = v;
	} 
	
	Vendor *getV(Vendor *v)
	{
		return m_v;
	} 
	
	void setV(Vendor *v)
	{
		m_v = v;
	} 
	
	virtual void sail()
	{
		m_v->sailapple();
	}


private:
	Vendor *m_v;
};

/*ִ�е���*/
class Waiter
{
public :
	Command *getCommand()
	{
		return m_command;
	} 
	
	void setCommand(Command *c)
	{
		m_command = c;
	} 
	
	void sail()
	{
		m_command->sail();
	}

private:
	Command *m_command;
};


/*���ö���*/
class AdvWaiter
{
public :
	AdvWaiter()
	{
		m_list = new list<Command *>;
		m_list->resize(0);
	}
	
	~AdvWaiter()
	{
		delete m_list;
	} 
	
	void setCommands(Command *c)
	{
		m_list->push_back(c);
	} 
	
	list<Command *> * getCommands()
	{
		return m_list;
	} 
	
	void sail()
	{
		for (list<Command *>::iterator it = m_list->begin(); it != m_list->end(); it++)
		{
			(*it)->sail();
		}
	}

private:
	list<Command *> *m_list;
};



int main()
{
#if 0
	/*ֱ�ӵ���sail, ��ȫ����װ���ù���*/
	Vendor *v = new Vendor;
	v->sailapple();
	v->sailbanana();
	delete v;
#endif

#if 0
	/*ͨ����װ��������е���*/
	Vendor *v = new Vendor;

	AppleCommand *ac = new AppleCommand(v);
	ac->sail();
	BananaCommand *bc = new BananaCommand(v);
	bc->sail();

	delete bc;
	delete ac;
	delete v;
#endif

#if 0

	/*ͨ��waiter���е���, �ֱ����*/
	Vendor *v = new Vendor;
	AppleCommand *ac = new AppleCommand(v);
	BananaCommand *bc = new BananaCommand(v);
	
	Waiter *w = new Waiter;


	w->setCommand(ac);
	w->sail();
	cout << "-----" << endl;
	w->setCommand(bc);
	w->sail();


	delete w;
	delete bc;
	delete ac;
	delete v;
#endif

	/*ͨ��waiter���н����������*/
	Vendor *v = new Vendor;
	AppleCommand *ac = new AppleCommand(v);
	BananaCommand *bc = new BananaCommand(v);

	AdvWaiter *w = new AdvWaiter;
	w->setCommands(ac);
	w->setCommands(bc);
	w->sail();


	delete w;
	delete bc;
	delete ac;
	delete v;


    return 0;
}

