// Mememto.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*存储历史信息的doamin数据类*/
class MememTo
{
private:
	string m_name;
	int m_age;
	

public :
	MememTo(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void setName(string name)
	{
		this->m_name = name;
	} 
	
	string getName()
	{
		return m_name;
	} 
	
	void setAge(int age)
	{
		this->m_age = age;
	} 
	
	int getAge()
	{
		return m_age;
	}


};

class Person
{

private:
	string m_name;
	int m_age;

public :
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void setName(string name)
	{
		this->m_name = name;
	}

	string getName()
	{
		return m_name;
	}

	void setAge(int age)
	{
		this->m_age = age;
	} 
	
	int getAge()
	{
		return m_age;
	} 
	void printT()
	{
		cout << "name: " << m_name << "age: " << m_age << endl;
	}

public:
	//创建备份
	MememTo *createMememTo()
	{
		return new MememTo(m_name, m_age);
	} 
	
	//恢复备份
	void SetMememTo(MememTo *memto)
	{
		m_name = memto->getName();
		m_age = memto->getAge();
	}


};


/*管理者*/
class Caretaker
{
private:
	MememTo *m_memto;

public :
	Caretaker(MememTo *mem)
	{
		this->m_memto = mem;
	}
	
	MememTo *getMememTo()
	{
		return m_memto;
	} 
	
	void setMememTo(MememTo *mem)
	{
		this->m_memto = mem;
	}


};


int main()
{
#if 0

	Person *p = new Person("张三", 18);
	p->printT();

	//创建备份
	Caretaker *ct = new Caretaker(p->createMememTo());

	//重新设置状态
	p->setAge(28);
	p->printT();

	//恢复信息
	p->SetMememTo(ct->getMememTo());
	p->printT();


	delete p;
	delete ct->getMememTo();
	delete ct;
#endif 


	Person *p = new Person("张三", 18);
	p->printT();

	//创建备份 (内部状态变成了外部状态)
	MememTo * membak = p->createMememTo(); p->setAge(28);
	p->printT();

	//恢复信息
	p->SetMememTo(membak);
	p->printT();

	delete p;
	delete membak;

    return 0;
}

