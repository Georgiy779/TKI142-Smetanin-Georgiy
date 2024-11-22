#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int inputa()
{
	setlocale(LC_ALL, "Russian");

	int a;
	printf("введите a.\n");
	scanf_s("%d", &a);
	return a;
}

int inputb()
{
	setlocale(LC_ALL, "Russian");

	int b;
	printf("введите b.\n");
	scanf_s("%d", &b);
	return b;
}

int outputc(int a, int b)
{
	setlocale(LC_ALL, "Russian");
	int c;
	c = a;
	a = b;
	b = c;
	printf("Вывод с\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	return 0;
}

int output(int a, int b)
{
	a ^= b ^= a ^= b;
	printf("Вывод\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	return 0;
}

int main()
{
	int a, b;
	a = inputa();
	b = inputb();
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	outputc(a, b);
	output(a, b);
	return 0;
}