#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

double tabylir(double x, double dx, double xk)
{
	double y;

	printf("x\ty\n");
	for (x;x < xk + 0.2;x = x + dx)
	{
		y = 3 * x - 4 * log(x) - 5;
		printf("%lf\t%lf\n", x, y);
	}
	return 0;

}
double proizvod()
{
	double a = 143, b = 777;
	printf("\nc\tproiz\n");
	for (int c = 1; c <= 9; c++)
	{
		printf("%d\t%lf\n", c, a * b * (double)c);
	}
	return 0;
}
int main()
{
	double x = 2, dx = 0.2,xk = 4;
	tabylir(x, dx, xk);
	proizvod();
	return 0;
}