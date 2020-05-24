#include<iostream>
using namespace std;

class Base{
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;

};

struct Pub_Derv : public Base {
	int f(){ return prot_mem; }
	//char g(){ return priv_men; }

} d1;
struct Priv_Derv :private Base{
	int f1() const{ return prot_mem; }
};
int main{

	Base * p = &d1;
	return 0;
}