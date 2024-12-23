#define _USE_MATH_DEFINES //for C 
#include <iostream>
#include <math.h> 

/**
* @brief ����� ����� � �������� 
* @param x �������� ��������� x
* @param y �������� ��������� y
* @param z �������� ��������� z
* @param a �������� ��������� a
* @param b �������� ��������� b
* @return 0 � ������ ������ 
*/ 
 
int main()
{
	const double x = -2.9, y = 15.5, z = 1.5;
	printf("a=%f\n", getA(x, y, z)); 
	printf("b=%f\n", getB(x, y, z)); 
}

double getA(const double x, const double y, const double z) 
{
	double a;
	a = sqrt(pow(x, 2) + y) - pow(y, 2) * pow(sin((x + z) / x), 3);
	return a;
}

double getB(const double x, const double y, const double z)
{
	double b;
	b = pow(cos(pow(x, 3)), 2) - x / (sqrt(pow(z, 2)) + pow(y, 2));
	return b;
}