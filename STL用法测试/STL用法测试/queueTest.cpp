#include<iostream>
#include<queue>
using namespace std;

int main(){
	queue<int> q;
	for (int i = 0; i < 10; i++){
		q.push(i);
	}
	if (!q.empty()){
		cout << "队列q非空！" << endl;
		cout << "q中有" << q.size() << "个元素" << endl;

	}
	
}