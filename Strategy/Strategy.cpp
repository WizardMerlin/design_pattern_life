// Strategy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;


/*Symmetric encryption*/
class Strategy
{
public :
	virtual void SymEncrypt() = 0;
};


class Des : public Strategy
{
public:
	virtual void SymEncrypt()
	{
		cout << "Des 加密" << endl;
	}
};


class AES : public Strategy
{
public :
	virtual void SymEncrypt()
	{
		cout << "AES 加密" << endl;
	}
};


class Context
{

public :
	Context(Strategy *strategy)
	{
		p = strategy;
	}

	void Operator()
	{
		p->SymEncrypt();
	}
private:
	Strategy *p;
};


int main(void)
{
	/* 
	//算法切换不影响client调用
	Strategy *strategy = NULL;
	strategy = new AES;
	strategy->SymEncrypt();
	delete strategy;
	strategy = new Des;

	strategy->SymEncrypt();
	delete strategy;
	*/

	Strategy *strategy = NULL;
	Context *ctx = NULL;

	strategy = new AES; //new DES
	ctx = new Context(strategy);
	ctx->Operator();

	delete strategy;
	delete ctx;

	return 0;
}