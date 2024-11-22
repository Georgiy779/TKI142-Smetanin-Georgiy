#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

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
	int i, j;
	double E = 0, k = 1, K = 1, sum = 0;
	for (i = 1;i < n + 1; i++)
	{
		k = k * i;
		for (j = 1;j < i + 5; j++)
		{
			K = K * j;
		}
		E = k / K;
		if (E >= e)
		{
			sum = sum + E;
			printf("Sum = %lf\n", sum);
		}
	}

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