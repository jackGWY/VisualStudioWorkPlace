#include<iostream>
using namespace std;

typedef enum
{
	Tank_Type_56,
	Tank_Type_96,
	Tank_Type_Num
}Tank_Type;

class Tank
{
public:
	virtual const string& type() = 0;
};

class Tank56 : public Tank
{
public:
	Tank56() :Tank(), m_strType("Tank56_56"){}
	const string& type() override
	{
		cout << m_strType.data() << endl;
		return m_strType;
	}
private:
	string m_strType;
};

class Tank96 :public Tank
{
public:
	Tank96() :Tank(),m_strType("Tank96")
	{

	}
	const string& type() override
	{
		cout << m_strType.data() << endl; 
		return m_strType;
	}
private:
	string m_strType;
};

class TankFactory
{
public:
	Tank* creatTank(Tank_Type type)
	{
		switch (type)
		{
		case Tank_Type_56:
			return new Tank56();
		case Tank_Type_96:
			return new Tank96();
		default:
			return nullptr;
		}
	}
};


// 简单工厂模式是通过集成模式实现的，被继承的类有虚函数
//int main()
//{
//	TankFactory* factory = new TankFactory;
//	Tank* tank56 = factory->creatTank(Tank_Type_56);
//	tank56->type();
//	Tank* tank96 = factory->creatTank(Tank_Type_96);
//	tank96->type();
//	delete tank96;
//	tank96 = nullptr;
//	delete tank56;
//	tank56 = nullptr;
//	delete factory;
//	factory = nullptr;
//	return 0;
//}