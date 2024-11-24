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
		printf("Некорректный способ инициализации массива! \n");

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

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	int n; // количество элементов массива

	printf("input n\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);

	//инециаллизация массива
	int* array = intmas(n);
	
	if (array != NULL)
	{
		//Вывод массива
		for (int i = 0; i < n; i++)
		{
			printf("array[%d] = %d\n", i, array[i]);
		}

		//Сумма отрицательных элементов кратных 10

		//Заменна первых k элементов массива в обрптном порядке

		//определяем пару соседних элементов произведение которых равно заданному числу

		free(array);
	}
	else
		printf("error");

	return 0;
}