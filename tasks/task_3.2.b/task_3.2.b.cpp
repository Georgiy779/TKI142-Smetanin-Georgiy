#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

double factorial(int n)
{
	double k = 1;

	for (int i = 1;i <= n; i++)
		k = k * i;

	return k;
}

int inputn()
{
	int n;
	printf("input n\n");
	scanf_s("%d", &n);
	return n;
}

double inpute()
{

	double e;
	printf("input e\n");
	scanf_s("%lf", &e);
	return e;
}

double sum(int n, double e)
{
	int i;
	double E = 0, sum = 0;
	for (i = 1;i < n + 1; i++)
	{
		E = factorial(i) / factorial(i + 4);

		if (E >= e)
			sum = sum + E;
	}
	printf("Sum = %lf\n", sum);
	return 0;
}

int main()
{

	int n;
	double e;
	n = inputn();
	e = inpute();
	sum(n, e);
	return 0;
}