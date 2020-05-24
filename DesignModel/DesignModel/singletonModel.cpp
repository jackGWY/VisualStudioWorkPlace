// ���̰߳�ȫ����������ģʽ

// ���캯����˽�еģ�����ͨ���������㣬��������ȷ�ʽʵ��������

// ����ʽһ��ʵ�֣����̰߳�ȫ��getInstance ���ص�ʵ��ָ����Ҫdelete

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