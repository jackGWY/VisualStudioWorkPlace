#include <iostream>

using namespace std;

extern class Line
{
public:
	double lenght;
	void setLength(double len);
	double getLength(void);
};

double Line::getLength(void)
{
	return lenght;
}

void Line::setLength(double len)
{
	lenght = len;
}