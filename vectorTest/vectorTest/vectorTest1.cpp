#include <iostream>
#include<vector>
#include<importTest.h>
using namespace std;

int main()
{
	Line line;
	vector<int> a(10, 0);
	cin >> a[2];
	cin >> a[5];
	cin >> a[6];

	int i;
	for (i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}