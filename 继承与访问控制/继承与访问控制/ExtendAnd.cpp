#include<iostream>
using namespace std;

class B
{

public:
	int pub_a;

	B(int i = 0, int j = 1, int k = 2){ pub_a = i; prot_b = j; priv_c = k; cout << "this is B()" << endl; }
	~B(){ cout << "this is ~B()"<<endl; }
	void display(){ cout << pub_a + prot_b + priv_c << " " << endl; }
protected:
	int prot_b;
private:
	int priv_c;

};

class D : public B
{
public:
	int pub_a;
	D(int i = 4, int j = 5, int k = 6){ pub_a = i; prot_b = j; priv_c = k; cout << "this is D()" << endl; }
	~D(){ cout << "this is ~D()"<<endl; }
	void display(){ cout << pub_a +prot_b+priv_c<< " " << endl; }
protected:
	int prot_b;
private:
	int priv_c;
};
class E : public D{
public:
	int t;
	E(int i, int j, int k){ pub_a = i; prot_b = j; t = k; }
};




class Base
{
public:
	std::size_t size() const{ return n; }
protected:
	std::size_t n = 2;
};

class Drived : private Base
{
public:
	using Base::size;
protected:
	using Base::n;
};

class TestDrived : public Drived
{
public:
	void print(){ cout<<n<<endl; }
protected:
	void print_T(){ cout << n << endl; }
};

int main()
{
	/*B b1;
	D d1(7, 1, 2);
	b1 = d1;
	d1.display();
	b1.display();
	E e(6, 7, 8);
	D d2 = e;
	d2.display();*/

// ²âÊÔusing
	
	return 0;
}
