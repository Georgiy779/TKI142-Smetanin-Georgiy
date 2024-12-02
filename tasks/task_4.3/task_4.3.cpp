#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int** intmas(int n, int m)
{
	srand(time(NULL));

	int f, i, j;
	int** array = NULL;

	printf("1 - keybord\n2 - random\n");
	scanf_s("%d", &f);
	printf("   -> %d\n\n", f);

	if (f == 1 || f == 2)
	{
		array = (int**)calloc(n, sizeof(int));
		for (int i = 0; i < n; i++)
			array[i] = (int*)calloc(m, sizeof(int));
	}
	else
		printf("Неправильно введённая операция! \n");

	if (f == 1)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf_s("%d", &array[i][j]);
	}

	if (f == 2)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				array[i][j] = rand();
	}

	return array;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	int n, m;

	printf("Ведите n.\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);

	printf("Ведите m.\n");
	scanf_s("%d", &m);
	printf("   -> %d\n\n", m);

	int** array = intmas(n, m);

	if (array != NULL)
	{
		//Вывод массива
		printf("Исходный массив\n");
		for (int i = 0; i < n; i++)
		{
			printf("\n");
			for (int j = 0; j < m; j++)
				printf("array[%d][%d] = %d\t", i, j, array[i][j]);
		}

		//free(array);
	}
	else
		printf("error");

	return 0;
}