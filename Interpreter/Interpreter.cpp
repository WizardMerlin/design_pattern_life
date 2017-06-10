// Interpreter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Context
{
private:
	int m_num;
	int m_res;

public :
	Context(int num)
	{
		m_num = num;
	}

public:
	void setNum(int num)
	{
		m_num = num;
	} 
	
	int getNum()
	{
		return m_num;
	} 
	
	void setRes(int res)
	{
		m_res = res;
	} 
	
	int getRes()
	{
		return m_res;
	}

};
class Expression
{
public :
	virtual void interpreter(Context *context) = 0;
};


class PlusExpression : public Expression
{
public :
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		num++;
		context->setNum(num);
		context->setRes(num);
	}
};


class MinusExpression : public Expression
{
public :
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		num--;
		context->setNum(num);
		context->setRes(num);
	}
};

int main(void)
{
	Context *pcxt = new Context(10);

	/*加法解释器*/
	Expression *e1 = new PlusExpression;
	e1->interpreter(pcxt);
	cout << "PlusExpression:" << pcxt->getRes() << endl;

	/*减法解释器*/
	Expression *e2 = new MinusExpression;
	e2->interpreter(pcxt);
	cout << "MinusExpression:" << pcxt->getRes() << endl;

	delete e2;
	delete e1;

    return 0;
}

