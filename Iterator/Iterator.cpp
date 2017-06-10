// Iterator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef int Object;
#define SIZE 5


class MyIterator
{
public :
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;
};

/*集合类*/
class Aggregate
{
public :
	virtual Object getItem(int index) = 0;
	virtual MyIterator *CreateIterator() = 0;
	virtual int getSize() = 0;
};


class ContreteIterator : public MyIterator
{
private:
	int _idx;
	Aggregate *_ag;

public :
	ContreteIterator(Aggregate *ag)
	{
		_ag = ag;
		_idx = 0;
	} 
	
	~ContreteIterator()
	{
		_ag = NULL;
		_idx = 0;
	} 

public :
	virtual void First()
	{
		_idx = 0;
	} 
	
	virtual void Next()
	{
		if (_idx < _ag->getSize())
		{
			_idx++;
		}
	} 
	
	virtual bool IsDone()
	{
		return (_idx == _ag->getSize());
	} 
	
	virtual Object CurrentItem()
	{
		return _ag->getItem(_idx);
	}

};


class ConcreteAggregate : public Aggregate
{
private:
	Object object[SIZE];

public :
	ConcreteAggregate()
	{
		/*初始化一些数据*/
		for (int i = 0; i<SIZE; i++)
		{
			object[i] = i + 1;
		}
	} 
	
	virtual ~ConcreteAggregate() { } 
	
	virtual Object getItem(int index)
	{
		return object[index];
	} 
	
	virtual MyIterator *CreateIterator()
	{
		return new ContreteIterator(this);
	} 
	
	virtual int getSize()
	{
		return SIZE;
	}

};

int main()
{
	Aggregate *ag = new ConcreteAggregate();//集合
	
	MyIterator *it = ag->CreateIterator();
	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << " ";
	} 
	
	//清理相关资源
	delete it;
	delete ag;

    return 0;
}

