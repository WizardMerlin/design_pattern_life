// Prototype.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
public:
	virtual Person *Clone() = 0;
	virtual void printT() = 0;
	virtual ~Person() 
	{
		cout << "deconstructor of Person" << endl;
	}
};

class JavaProgrammer : public Person
{
	public :
	JavaProgrammer()
	{
		this->m_name = "";
		this->m_age = 0;
		m_resume = NULL;
	} 
		
	JavaProgrammer(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
		m_resume = NULL;
	} 
	
	~JavaProgrammer()
	{
		if (m_resume != NULL)
		{
			free(m_resume);
			m_resume = NULL;
		}
	} 
	
	void setResume(char *resume)
	{
		m_resume = new char[strlen(resume) + 1];
		strcpy(m_resume, resume);
	}

	virtual Person *Clone()
	{
		JavaProgrammer *p = new JavaProgrammer;
		*p = *this;
		return p;
	} 
	
    virtual void printT()
	{
		cout << "m_name:" << m_name.c_str() << "\t" << "m_age:" << m_age << "\t";
		if (m_resume != NULL)
		{
			cout << m_resume << endl;
		}
	}

private:
	string m_name;
	int m_age;
	char *m_resume;  /*����������ǳ����*/
};

int main(void)
{

	JavaProgrammer j1("tom", 30);
	j1.setResume("java programmer");
	j1.printT();

	Person *p2 = j1.Clone();
	p2->printT();

	delete p2;

	j1.printT(); //m_resumeӦ��������

    return 0;
}

