#define USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double inputx()
{
	double x;
	printf("input x.\n");
	scanf_s("%lf", &x);
	return x;
}

double output(double x, double a)
{
	double y;
	if (x > a)
	{
		y = x * pow(sin(x), 2);
	}
	else
	{
		y = x * pow(cos(x), 2);
	}
	return y;
}

int main()
{
	double a = 2.5, x, y;
	x = inputx();
	printf("x = %lf\n", x);
	y = output(x, a);
	printf("y = %lf\n", y);
	return 0;
}