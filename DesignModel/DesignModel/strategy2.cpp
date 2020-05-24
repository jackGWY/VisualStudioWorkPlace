#include<iostream>
#include<functional>

using namespace std;
void adcHurt()
{
	cout << "Adc Hurt" << endl;

}

void apcHurt()
{
	cout << "Apc Hurt" << endl;

}

// ������ɫ�࣬ʹ�ô�ͳ�ĺ���ָ��
class Soldier
{
public:
	typedef void(*Function)();
	Soldier(Function fun):m_fun(fun){}
	void attack()
	{
		m_fun();
	}
private:
	Function m_fun;
};

//������ɫ�࣬ʹ��std::function<>
class Mage
{
public:
	typedef std::function<void()> Function;
	Mage(Function fun) :m_fun(fun){}
	void attack()
	{
		m_fun();
	}
private:
	Function m_fun;
};

int main()
{
	Soldier* soldier = new Soldier(apcHurt);
	soldier->attack();
	delete soldier;
	soldier = nullptr;
	return 0;
}