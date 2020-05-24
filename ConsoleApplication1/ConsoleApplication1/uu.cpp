#include<stdio.h>
struct D {
	char b;
	short c;
	int a;
	
	//double e;
} d;
int main()
{
	printf("%d", sizeof(d));
}