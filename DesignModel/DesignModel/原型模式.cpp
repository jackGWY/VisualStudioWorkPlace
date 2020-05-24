// 拷贝，reuturn new calssName(*this)

#include<iostream>
using namespace std;

//提供一个克隆类
class Clone
{
public:
	virtual Clone* clone() = 0;
	virtual void show() = 0;
};

class Sheep : public Clone
{
public:
	Sheep(int id, string name) :Clone(), m_id(id), m_name(name)
	{
		cout << "Sheep() id address:" << &m_id << endl;
		cout << "Sheep() name address:" << &m_name << endl;
	}
	~Sheep(){}
	// 关键代码拷贝函数
	Sheep(const Sheep& obj)
	{
		this->m_id = obj.m_id;
		this->m_name = obj.m_name;
		cout << "Sheep(const Sheep&obj) id address:" << &m_id << endl;
		cout << "Sheep(const Sheep&obj) name address:" << &m_name<< endl;

	}
private:
	int m_id;
	string m_name;
};