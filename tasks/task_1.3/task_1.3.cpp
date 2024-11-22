#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

double inputm()
{
	setlocale(LC_ALL, "Russian");

	double m;
	printf("Ввидите m в кг.\n");
	scanf_s("%lf", &m);
	return m;
}

double inputS()
{
	setlocale(LC_ALL, "Russian");

	double S;
	printf("Ввидите S в м^2.\n");
	scanf_s("%lf", &S);
	return S;
}

double output(double m, double S, double g)
{
	double P;
	P = (m * g) / S;
	printf("m = %lf\n", m);
	printf("s = %lf\n", S);
	return P;
}

int main()
{
	double m, S, P, g = 9.8;
	m = inputm();
	S = inputS();
	P = output(m, S, g);
	printf("P = %lf\n", P);
	return 0;
}