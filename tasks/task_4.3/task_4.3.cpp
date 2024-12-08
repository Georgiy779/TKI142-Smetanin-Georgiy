#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <string.h>

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
		//Выделение памяти для двумерного массива
		array = (int**)calloc(n, sizeof(int*));
		for (int i = 0; i < n; i++)
			array[i] = (int*)calloc(m, sizeof(int));
	}
	else
		printf("Неправильно введённая операция! \n");

	if (f == 1)
	{
		//Ввод двумерного массива с клавиатуры
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf_s("%d", &array[i][j]);
	}

	if (f == 2)
	{
		//Ввод двумерного массива на рандом
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				array[i][j] = rand();
	}

	return array;
}

//Замена моксемалных элементов строк на 0
int zum(int** array, int n, int m)
{
	int max, maxj; //i = 0, j = 0, ;

	for (int i=0; i < n; i++)
	{
		max = array[i][0];
		maxj = 0;

		for (int j=0; j < m; j++)
		{
			if (max < array[i][j])
			{
				max = array[i][j];
				maxj = j;
			}
		}
		array[i][maxj] = 0;

	}
	printf("\nПосле замены максималных элементов на 0:");
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < m; j++)
			printf("%d\t", array[i][j]);
	}
	return 0;
}

//Вставление строки из нулей, перед строками, первый элемент которых делится на 3
int** insert(int** array, int n, int m, int* s)
{
	*s = 0; //Индекс (количество) строк в новом масиве

	int** arrayb = NULL;

	for (int i = 0; i < n; i++)
	{
		arrayb = (int**)realloc(arrayb, (*s + 1) * sizeof(int*)); // Выделяем память на ещё один элемент в массиве
		arrayb[*s] = (int*)calloc(m, sizeof(int));

		if (array[i][0] != 0 && array[i][0] % 3 == 0)
		{
			//заполнение нулями
			for (int j = 0; j < m; j++)
				arrayb[*s][j] = 0;

			(*s)++;//Увеличеваем количество строк в новом массиве

			arrayb = (int**)realloc(arrayb, (*s + 1) * sizeof(int*)); // Выделяем память на ещё один элемент в массиве
			arrayb[*s] = (int*)calloc(m, sizeof(int));

		}

		//копирование текущей строки
		for (int j = 0; j < m; j++)
			arrayb[*s][j] = array[i][j];
		
		(*s)++;
	}

	return arrayb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	int n, m, s;

	printf("Ведите n.\n");//n количество строк
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);

	printf("Ведите m.\n");//m количество столбцов
	scanf_s("%d", &m);
	printf("   -> %d\n\n", m);

	int** array = intmas(n, m);//выделение память на указатель указателей

	if (array != NULL)//проверка на правильный ввод массива
	{
		//Вывод массива
		printf("Исходный массив:");
		for (int i = 0; i < n; i++)
		{
			printf("\n");
			for (int j = 0; j < m; j++)
				printf("%d\t", array[i][j]);
		}
		printf("\n");

		//Замена моксемалных элементов строк на 0
		zum(array, n, m);

		//Вставление строки из нулей, перед строками, первый элемент которых делится на 3
		int** arrayb = insert(array, n, m, &s);

		printf("\n\nМассив после вставки:");
		for (int i = 0; i < s; i++)
		{
			printf("\n");
			for (int j = 0; j < m; j++)
				printf("%d\t", arrayb[i][j]);
		}
		printf("\n");


		//Очистка памяти
		for (int i = 0; i < n; i++)
			free(array[i]);
		free(array);

		for (int i = 0; i < s; i++)
			free(arrayb[i]);
		free(arrayb);
	}
	else
		printf("error");

	return 0;
}