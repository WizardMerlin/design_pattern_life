// Visitor.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;


//�ͻ�ȥ���а���ҵ��
//m ���ͻ�
//n ����Ա
//��Ҫ �����Ҫ����Ĳ����ֿ��� ��ͬ�Ĺ�Ա���԰���ͬ�����ߵ�ҵ��
class Element;

/*�����߷��ʹ�Ա*/
class Visitor
{
public :
	virtual void visit(Element *element) = 0;
};


/*��Ա���ܿͻ�����*/
class Element
{
public :
	virtual void accept(Visitor *v) = 0;
	virtual string getName() = 0;
};

/*��Ա A Ա��*/
class EmployeeA : public Element
{
public :
	EmployeeA(string name)
	{
		m_name = name;
	}

	virtual void accept(Visitor *v)
	{
		v->visit(this);
	} 

	virtual string getName()
	{
		return m_name;
	}

private:
	string m_name;
};


//��Ա B Ա��
class EmployeeB : public Element
{
	public :
	EmployeeB(string name)
	{
		m_name = name;
	} 
	
	virtual void accept(Visitor *v)
	{
		v->visit(this);
	}
	string getName()
	{
		return m_name;
	}
private:
	string m_name;
};
class VisitorA : public Visitor
{
	
	public :
	virtual void visit(Element *element)
	{
		cout << "ͨ��" << element->getName() << "�� A ҵ��" << endl;
	}
};


class VisitorB : public Visitor
{
	public :
	virtual void visit(Element *element)
	{
		cout << "ͨ��" << element->getName() << "�� B ҵ��" << endl;
	}
};

//�ṩ���������Ĺ���
class Employees : public Element
{
public :
	Employees()
	{
		m_list = new list<Element *>;
	}

	virtual void accept(Visitor *v)
	{
		for (list<Element *>::iterator it = m_list->begin(); it != m_list->end(); it++)
		{
			(*it)->accept(v);
		}
	} 
	
	string getName()
	{
		return m_name;
	}

public:
	void addElement(Element *e)
	{
		m_list->push_back(e);
	} 
	
	void removeElement(Element *e)
	{
		m_list->remove(e);
	}
private:
	list<Element *> *m_list;
	string m_name;
};

int main()
{
#if 0
	EmployeeA *eA = new EmployeeA("��Ա A");
	VisitorA *vA = new VisitorA;
	VisitorB *vB = new VisitorB;

	eA->accept(vA);
	eA->accept(vB);

	delete eA;
	delete vA;
	delete vB;
#endif


	EmployeeA *eA = new EmployeeA("��Ա A");
	EmployeeA *eB = new EmployeeA("��Ա B");
	Employees *es = new Employees;

	es->addElement(eA);
	es->addElement(eB);

	VisitorA *vA = new VisitorA;// Aҵ��
	VisitorB *vB = new VisitorB;// Bҵ��

	es->accept(vA);
	cout << "------------------" << endl;
	es->accept(vB);


	delete eA;
	delete eB
		;
	delete vA;
	delete vB;


    return 0;
}

