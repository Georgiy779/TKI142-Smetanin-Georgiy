#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include <locale.h>

double inputXa()
{
	double a;
	printf("input X1.\n");
	scanf_s("%lf", &a);
	return a;
}

double inputYa()
{
	double a;
	printf("input Y1.\n");
	scanf_s("%lf", &a);
	return a;
}

double inputXb()
{
	double a;
	printf("input X2.\n");
	scanf_s("%lf", &a);
	return a;
}

double inputYb()
{
	double a;
	printf("input Y2.\n");
	scanf_s("%lf", &a);
	return a;
}

double inputXc()
{
	double a;
	printf("input X3.\n");
	scanf_s("%lf", &a);
	return a;
}

double inputYc()
{
	double a;
	printf("input Y3.\n");
	scanf_s("%lf", &a);
	return a;
}

int check(double xa, double ya, double xb, double yb, double xc, double yc)
{
	double flag;
	if ((xc - xa) / (xb - xa) == (yc - ya) / (yb - ya))
	{
		printf("Точки лежат на одной прямой\n");
		return 1;
	}
	else
	{
		printf("Точки не лежат на одной прямой\n");
	}
	return 0;
}

double calc_anglу(double xa, double ya, double xb, double yb, double xc, double yc)
{
	//считаем длины отрезков
	double ba = sqrt( pow((xb - xa), 2.0) + pow((yb - ya), 2.0) );
	double bc = sqrt( pow((xb - xc), 2.0) + pow((yb - yc), 2.0) );
	double ac = sqrt( pow((xa - xc), 2.0) + pow((ya - yc), 2.0) );

	return (
		// это в радианах
		acos((pow(ba, 2.0) + pow(bc, 2.0) - pow(ac, 2.0)) / (2.0 * ba * bc))
		* 180 / M_PI // а так в градусах
		);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	double xa, ya, xb, yb, xc, yc;
	xa = inputXa();
	printf("x1 = %lf\n", xa);

	ya = inputYa();
	printf("y1 = %lf\n", ya);

	xb = inputXb();
	printf("x2 = %lf\n", xb);

	yb = inputYb();
	printf("y2 = %lf\n", yb);

	xc = inputXc();
	printf("x3 = %lf\n", xc);

	yc = inputYc();
	printf("y3 = %lf\n", yc);

	int c = check(xa, ya, xb, yb, xc, yc);
	if (c == 0)
	{
	//Вычеслим угол
		double angle = calc_anglу(xa, ya, xb, yb, xc, yc);
		printf("Угол ABC = %lf\n", angle);
	}
	return 0;
}