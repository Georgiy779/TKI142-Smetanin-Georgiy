#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>
#include <time.h> // чтобы использовать функцию time()

int* intmas(int n)
{
	srand(time(NULL));

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
	int min_val, sred_elem_mas, min_index;
	
	sred_elem_mas = (n-1)/2; //Находим средний элемент массива

	//Находим минимальный элемент массива
	min_val = array[0];
	min_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < min_val)
		{
			min_val = array[i];
			min_index = i;
		}
	}
	
	printf("Минимальный элемент массива = %d\n", array[min_index]);
	printf("Средний элемент массива = %d\n", array[sred_elem_mas]);

	//Меняем местами средний и минимальный элемент массива
	array[sred_elem_mas] ^= array[min_index] ^= array[sred_elem_mas] ^= array[min_index];

	for (int i = 0; i < n; i++)
		printf("array[%d] = %d\n", i, array[i]);

	return 0;
}

// удалить все элементы где есть цифра X
int* delit(int* array, int n, int* s, char X)
{
	int* arrayb = NULL;
	char* str = (char*)calloc(20, sizeof(char)); // массив символов с максемальной длиной 20
	*s = 0;

	for (int i = 0; i < n; i++)
	{
		int sl = snprintf(str, sizeof str, "%d", array[i]); // преобразуем элемент массива array в строку


		//проверяем есть ли в строке символ X
		int k = 0;
		for (k = 0; k < sl; k++)
		{
			if (str[k] == X)
				break;
		}

		//если k = sl в строке нету символа x, значит это значение надо записить в новый массив
		if (k == sl)
		{
			*s = *s + 1; //увеличиваю количество элементов в новом массиве
			arrayb = (int*)realloc(arrayb, *s * sizeof(int)); // Выделяем память на ещё один элемент в массиве
			arrayb[*s - 1] = array[i]; // записываем элемент в новый массив
		}
		
	}
	
	free(str);
	return arrayb;
}

int* intmasb(int* array, int n)
{
	int* arrayb = NULL;
	arrayb = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 0)
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

	int n, s; //n - количество элементов массива

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
		printf("Исходный массив\n");
		for (int i = 0; i < n; i++)
			printf("array[%d] = %d\n", i, array[i]);

		//Замена минимального элемента массива на средний.
		zum_sred(array, n);

		//Удаление всех элементов, в записи которых есть цифра 5. 
		printf("\nУдаление всех элементов, в записи которых есть цифра 5.\n");
		int* arraya = delit(array, n, &s, '5');
		for (int i = 0; i < s; i++)
			printf("arraya[%d] = %d\n", i, arraya[i]);

		//Сформировать новый массив на основе существующего.
		printf("\nСформировать новый массив на основе существующего.\n");
		int* arrayb = intmasb(array, n);
		for (int i = 0; i < n; i++)
			printf("arrayb[%d] = %d\n", i, arrayb[i]);

		free(array);
		free(arraya);
		free(arrayb);
	}
	else
		printf("error");

	return 0;
}