#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>

int* intmas(int n)
{
	int f, i;
	int* array = NULL;

	printf("1 - keybord\n2 - random\n");
	scanf_s("%d", &f);
	printf("   -> %d\n\n", f);

	if (f == 1 || f == 2)
		array = (int*)calloc(n, sizeof(int));
	else
		printf("Неправильно введённая операция! \n");

	if (f == 1)
	{
		for (i = 0; i < n; i++)
			scanf_s("%d", &array[i]);
	}

	if (f == 2)
	{
		for (i = 0; i < n; i++)
			array[i] = rand();
	}

	return array;
}

int zum_sred(int* array, int n)
{
	int g, sred_elem_mas, min;
	double sred = 0;
	for (int i = 0; i < n; i++)
	{
		sred = sred + array[i];
	}
	sred = sred / n;

	//Находим средний элемент массива
	g = array[0];
	sred_elem_mas = 0;
	for (int i = 0; i < n; i++)
	{
		if (fabs(array[i] - sred) < fabs(array[i - 1] - sred))
		{
			g = array[i];
			sred_elem_mas = i;
		}
	}
	printf("Средний элемент массива = %d\n", array[sred_elem_mas]);

	//Находим минимальный элемент массива
	g = array[0];
	min = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < g)
		{
			g = array[i];
			min = i;
		}
	}
	
	printf("Минимальный элемент массива = %d\n", array[min]);

	//Меняем местами средний и минимальный элемент массива
	g = array[sred_elem_mas];
	array[sred_elem_mas] = array[min];
	array[min] = g;
	printf("Минимальный элемент массива = %d\n", array[min]);
	printf("Средний элемент массива = %d\n", array[sred_elem_mas]);

	for (int i = 0; i < n; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	return 0;
}

//int delit(int* array, int n)
//{
//	return 0;
//}

int* intmasb(int* array, int n)
{
	int* arrayb = 0;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 % 2 == 0)
			arrayb[i] = pow(array[i], 2);
		else
			arrayb[i] = 2 * array[i];
	}
	return arrayb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	int n, g; //n - количество элементов массива

	printf("Ведите n (не чётный).\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);
	if (n % 2 ==0)
	{
		printf("Неправильно введённая операция! \n");
		return 0;
	}
	//Создание массива
	int* array = intmas(n);

	if (array != NULL)
	{
		//Вывод массива
		for (int i = 0; i < n; i++)
			printf("array[%d] = %d\n", i, array[i]);

		//Замена минимального элемента массива на средний.
		zum_sred(array, n);

		//Удаление всех элементов, в записи которых есть цифра 5. 
		//delit(array, n);

		//Сформировать новый массив на основе существующего.
		int* arrayb = intmasb(array, n);
		for (int i = 0; i < n; i++)
			printf("arrayb[%d] = %d\n", i, arrayb[i]);

		free(array);
		free(arrayb);
	}
	else
		printf("error");

	return 0;
}