//线程安全的懒汉单例模式
#include<iostream>
#include<mutex>
std::mutex mt;

class Singleton
{
public:
	static Singleton*  getInstance();
private:
	Singleton(){}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = NULL;
Singleton* Singleton::getInstance()
{
	if (m_pSingleton == NULL)
	{
		mt.lock();
		if (m_pSingleton == NULL)
		{
			m_pSingleton = new Singleton();
		}
		mt.unlock();
	}
	return m_pSingleton;
}
