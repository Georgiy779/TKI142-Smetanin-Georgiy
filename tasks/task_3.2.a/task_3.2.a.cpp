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

double sum(int n)
{
	int i, j;
	double E = 0, k = 1, K = 1, sum = 0;
	for (i = 1;i < n + 1; i++)
	{
		printf("i = %d\n", i);
		k = k * i;
		printf("k = %lf\n", k);
		for (j = 1; j < i + 5; j++)
		{
			printf("j = %d\n", j);
			K = K * j;
			printf("k= %lf\n", K);
		}
			E = k / K;
			printf("E = %lf\n", E);
			sum = sum + E;
			printf("sum = %lf\n", sum);
	}
	return 0;
}

int main()
{
	int n;
	n = inputn();
	sum(n);
	return 0;
}