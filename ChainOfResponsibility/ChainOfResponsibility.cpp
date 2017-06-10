// ChainOfResponsibility.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CarHandle
{
public :
	void setNextHandle(CarHandle *carhandle)
	{
		if (carhandle != NULL) {
			this->carhandle = carhandle;
		}
		else 
		{
			this->carhandle = NULL;
		}
	}

public:
	virtual void HandleCar() = 0;

protected:
	CarHandle *carhandle;
};

class CarHandleHead : public CarHandle
{
public :
	virtual void HandleCar()
	{
		cout << "head" << endl;
		if (this->carhandle != NULL)
		{
			carhandle->HandleCar();
		}
	}

};

class CarHandleBody : public CarHandle
{
public :
	virtual void HandleCar()
	{
		cout << "body" << endl;
		if (this->carhandle != NULL)
		{
			carhandle->HandleCar();
		}
	}
};

class CarHandleTail : public CarHandle
{
public :
	virtual void HandleCar()
	{
		cout << "tail" << endl;
		if (this->carhandle != NULL)
		{
			carhandle->HandleCar();
		}
	}
};



int main()
{
	/*����������ù���*/
	CarHandleHead *head = new CarHandleHead;
	CarHandleBody *body = new CarHandleBody;
	CarHandleTail *tail = new CarHandleTail; 
	
	head->setNextHandle(body);
	body->setNextHandle(tail);
	tail->setNextHandle(NULL);
	
	//����
	head->HandleCar();

	delete head;
	delete body;
	delete tail;

    return 0;
}

