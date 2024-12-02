#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>

double fun_calcul(double x)
{
	double func;

	func =((log(x))/2);

	return func;
}

double sum_calcul(double x, int n)
{
	double sum = 0;

	for (int i = 0; i < n + 1; i++)
	{
		sum = sum + ((1/((2*n) + 1)) * pow( ((x - 1)/(x + 1)), ((2*n) +1)) );
	}

	return sum;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	double x, func, sum;
	int n;

	printf("Введите точность n\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);


	for (x = 0.2; x <= 1;)
	{
		func = fun_calcul(x);

		sum = sum_calcul(x, n);

		printf("x = %lf\t y = %lf\t sum = %lf\n", x, func, sum);

		x = x + 0.0001;
	}

	

	return 0;
}