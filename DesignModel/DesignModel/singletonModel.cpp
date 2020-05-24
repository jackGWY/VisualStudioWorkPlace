// 非线程安全的懒汉单例模式

// 构造函数是私有的，不能通过复制运算，拷贝构造等方式实例化对象

// 懒汉式一般实现：非线程安全，getInstance 返回的实例指针需要delete

class Singleton
{
public:
	static Singleton* getInstance();
	~Singleton(){}
private:
	Singleton(){}
	Singleton(const Singleton& obj) = delete;
	Singleton& operator = (const Singleton& ogj) = delete;
	static Singleton * m_pSingleton;
};

Singleton* Singleton::m_pSingleton = nullptr;
Singleton*Singleton::getInstance()
{
	if (m_pSingleton == nullptr)
	{
		m_pSingleton = new Singleton;
	}
	return m_pSingleton;
}