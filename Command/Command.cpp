// Command.cpp : 定义控制台应用程序的入口点。
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
		cout << "卖香蕉" << endl;
	} 
	
	void sailapple()
	{
		cout << "卖苹果" << endl;
	}
};


class Command
{
public :
	virtual void sail() = 0;
};

/*封装的具体调用1*/
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

/*封装的具体调用2*/
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

/*执行调用*/
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


/*调用队列*/
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
	/*直接调用sail, 完全不封装调用过程*/
	Vendor *v = new Vendor;
	v->sailapple();
	v->sailbanana();
	delete v;
#endif

#if 0
	/*通过封装的命令进行调用*/
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

	/*通过waiter进行调用, 分别调用*/
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

	/*通过waiter队列进行整体调用*/
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

