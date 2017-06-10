// Mememto.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*�洢��ʷ��Ϣ��doamin������*/
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
	//��������
	MememTo *createMememTo()
	{
		return new MememTo(m_name, m_age);
	} 
	
	//�ָ�����
	void SetMememTo(MememTo *memto)
	{
		m_name = memto->getName();
		m_age = memto->getAge();
	}


};


/*������*/
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

	Person *p = new Person("����", 18);
	p->printT();

	//��������
	Caretaker *ct = new Caretaker(p->createMememTo());

	//��������״̬
	p->setAge(28);
	p->printT();

	//�ָ���Ϣ
	p->SetMememTo(ct->getMememTo());
	p->printT();


	delete p;
	delete ct->getMememTo();
	delete ct;
#endif 


	Person *p = new Person("����", 18);
	p->printT();

	//�������� (�ڲ�״̬������ⲿ״̬)
	MememTo * membak = p->createMememTo(); p->setAge(28);
	p->printT();

	//�ָ���Ϣ
	p->SetMememTo(membak);
	p->printT();

	delete p;
	delete membak;

    return 0;
}

