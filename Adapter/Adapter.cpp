// Adapter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Current18v
{
public :
	 virtual void use18vCurrent()
	{
		cout << "ʹ�� 18v �Ľ�����" << endl;
	}
};


class Current220v
{
public :
	void use220vCurrent()
	{
		cout << "ʹ�� 220v �Ľ�����" << endl;
	}

};


class Adapter : public Current18v
{
public :
	Adapter(Current220v *p220v)
	{
		m_p220v = p220v;
	}
	
	virtual void use18vCurrent()
	{
		cout << "ͨ��adapter, ";
		m_p220v->use220vCurrent();
	}

private:
	Current220v *m_p220v;
};



int main()
{
	Current220v *p220v = new Current220v;

	Current18v *padapter = new Adapter(p220v);
	padapter->use18vCurrent();


	delete p220v;
	delete padapter;

    return 0;
}

