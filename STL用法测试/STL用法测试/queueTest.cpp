#include<iostream>
#include<queue>
using namespace std;

int main(){
	queue<int> q;
	for (int i = 0; i < 10; i++){
		q.push(i);
	}
	if (!q.empty()){
		cout << "����q�ǿգ�" << endl;
		cout << "q����" << q.size() << "��Ԫ��" << endl;

	}
	
}