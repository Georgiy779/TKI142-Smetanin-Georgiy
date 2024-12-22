#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int inputAx(int Ax)
{ 

	printf("Input Ax\n");
	scanf_s ("%d", &Ax);
	return Ax;
}

int inputAy(int Ay)
{
	printf("Input Ay\n"),
	scanf_s("%d", &Ay);
	return Ay;
}

int inputBx(int Bx)
{
	printf("Input. Bx\n");
	scanf_s("%d", &Bx);
	return Bx;
}

int inputBy(int By)
{
	printf("Input By\n");
	scanf_s("%d", &By);
	return By;
}

double output(int Ax, int Ay, int Bx, int By)
{
	double S = sqrt(pow(Bx - Ax, 2) + pow(By - Ay, 2));
	printf("S = %f", S);
	return 0;
}
int main()
{
	int Ax = 0, Ay = 0, Bx = 0, By= 0;
	Ax = inputAx(Ax);
	Ay = inputAy(Ay);
	Bx = inputBx(Bx);
	By = inputBy(By);
	output(Ax, Ay, Bx, By);
	return 0;
}