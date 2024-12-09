#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>
#include <time.h> // чтобы использовать функцию time()
#include <string.h>

//Вводл двумерного массива
int** intmas(int n, int m)
{
	//Для работы раномайзера
	srand(time(NULL));

	//f - пераметр введённый для определения способа ввода массива
	//i - переменная введённая для ввода массива
	//j - переменная введённая для ввода массива
	int f, i, j;
	//array - Указатель на указатель введённый для создания двумерного массива
	int** array = NULL;

	//Определение способа ввода массива
	printf("1 - keybord\n2 - random\n");
	scanf_s("%d", &f);
	printf("   -> %d\n\n", f);

	//Проверка правильности ввода переменной f
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
		//Заполнение двумерного массива с клавиатуры
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf_s("%d", &array[i][j]);
	}

	if (f == 2)
	{
		//Заполнение двумерного массива случайными числами
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				array[i][j] = rand();
	}

	//возвращение массива
	return array;
}

//Замена максемалных элементов строк на 0
int zum(int** array, int n, int m)
{
	//max - значение максимального элемента строки массива
	//maxj - индекс максимального элемента строки массива
	int max, maxj;

	for (int i=0; i < n; i++)
	{
		max = array[i][0];
		maxj = 0;

		//определение максимального элемента строки массива
		for (int j=0; j < m; j++)
		{
			if (max < array[i][j])
			{
				max = array[i][j];
				maxj = j;
			}
		}
		//приравнивание макчимального элемента строки к 0
		array[i][maxj] = 0;

	}
	printf("\nПосле замены максималных элементов на 0:");
	//Вывод обновлённого массива
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
	//s - индекс (количество) строк в новом масиве
	*s = 0;

	//arrayb - указатель на указатель введённый для создания двумерного массива
	int** arrayb = NULL;

	for (int i = 0; i < n; i++)
	{
		// Выделяем память на ещё один элемент в массиве
		arrayb = (int**)realloc(arrayb, (*s + 1) * sizeof(int*)); 
		arrayb[*s] = (int*)calloc(m, sizeof(int));

		if (array[i][0] != 0 && array[i][0] % 3 == 0)
		{
			//заполнение нулями
			for (int j = 0; j < m; j++)
				arrayb[*s][j] = 0;

			//Увеличеваем количество строк в новом массиве
			(*s)++;

			// Выделяем память на ещё один элемент в массиве
			arrayb = (int**)realloc(arrayb, (*s + 1) * sizeof(int*)); 
			arrayb[*s] = (int*)calloc(m, sizeof(int));

		}

		//копирование текущей строки
		for (int j = 0; j < m; j++)
			arrayb[*s][j] = array[i][j];
		
		//Увеличеваем количество строк в новом массиве
		(*s)++;
	}

	//возвращение массива
	return arrayb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	//n - количество строк в массиве
	//m - количество столбцов в массиве
	//s - количество строк в новом массиве
	int n, m, s;

	//Ввод количества строк в массиве
	printf("Ведите n.\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);

	//Ввод количество столбцов в массиве
	printf("Ведите m.\n");
	scanf_s("%d", &m);
	printf("   -> %d\n\n", m);

	//выделение память на указатель указателей
	int** array = intmas(n, m);

	//проверка на правильный ввод массива
	if (array != NULL)
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

		//Вывод обновлённого массива
		printf("\n\nМассив после вставки:");
		for (int i = 0; i < s; i++)
		{
			printf("\n");
			for (int j = 0; j < m; j++)
				printf("%d\t", arrayb[i][j]);
		}
		printf("\n");


		//Очистка памяти от первого массива
		for (int i = 0; i < n; i++)
			free(array[i]);
		free(array);

		//Очистка памяти от второго массива
		for (int i = 0; i < s; i++)
			free(arrayb[i]);
		free(arrayb);
	}
	else
		printf("error");

	return 0;
}