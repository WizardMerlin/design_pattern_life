// Singleton.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*懒汉式(直到需要创建该类的实例时才进行初始化)*/
class Singelton
{
private:
	static Singelton *m_singer;
	static int m_count;

	Singelton()
	{
		m_singer = NULL;
		m_count = 0;
		cout << "constructor Singelton " << endl;
	}
	~Singelton() {}
	Singelton(const Singelton& obj) {}
	Singelton& operate(const Singelton& obj) {}


public:
	static Singelton *getInstance()
	{
		//懒汉式： 1 每次获取实例都要判断 2 多线程会有问题
		if (m_singer == NULL) 
		{
			m_singer = new Singelton;
		}
		
		return m_singer;
	} 
	
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}

};

Singelton *Singelton::m_singer = NULL; /*懒汉式 并没有创建单例对象*/
int Singelton::m_count = 0;



/*恶汉式(不管是否创建实例, 都要进行初始化)*/
class Singelton2
{
private :
	static Singelton2 *m_singer;
	static int m_count;

	Singelton2()
	{
		m_singer = NULL;
		m_count = 0;
		cout << "constructor Singelton2" << endl;
	}

	~Singelton2()
	{
		cout << "deconstructor called" << endl;
	}

	Singelton2(const Singelton& obj) {}
	Singelton2& operate(const Singelton& obj) {}

public:



	static Singelton2 *getInstance()
	{
		// if (m_singer == NULL )
		// {
		// m_singer = new Singelton2;
		// }
		return m_singer;
	} 
	
	static void Singelton2::releaseInstance()
	{
		/*避免重析构*/
		if (m_singer != NULL) 
		{
			delete m_singer;
			m_singer = NULL;
			m_count = 0;
		}
		else {
			cout << "already released." << endl;
		}
	} 
	
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}

};

Singelton2 *Singelton2::m_singer = new Singelton2;
int Singelton2::m_count = 0;




int main()
{
	cout << "Main Function Begin" << endl;
#if 0

	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();
	
	if (p1 != p2)
	{
		cout << "they are not the same thing" << endl;
		
	} else {
		cout << "using the same obj" << endl;
	} 
	
	p1->printT();
	p2->printT();

#endif

	Singelton2 *p1 = Singelton2::getInstance(); 
	Singelton2 *p2 = Singelton2::getInstance();

	if (p1 != p2)
	{
		cout << "they are not the same thing" << endl;
	} else {
		cout << "using the same obj" << endl;
	}

	p1->printT();
	p2->printT();
	
	//delete p1;   //private method
	//delete p2;   //private method
	Singelton2::releaseInstance();
	
	Singelton2::releaseInstance(); //already released

	cout << "Main Function End" << endl;

    return 0;
}

