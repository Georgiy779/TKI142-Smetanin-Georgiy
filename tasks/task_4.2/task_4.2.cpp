#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>
#include <time.h> // чтобы  использовать функцию time()

//Ввод массива
int* intmas(int n)
{
	//для работы рандомайзера
	srand(time(NULL));

	//f - пераметр введённый для определения способа ввода массива
	//i - индекс элемента массива
	int f, i;
	//array - указатель введённый для создания массива
	int* array = NULL;

	//Определение способа ввода массива
	printf("1 - keybord\n2 - random\n");
	scanf_s("%d", &f);
	printf("   -> %d\n\n", f);

	//Проверка правильного ввода переменной f
	if (f == 1 || f == 2)
		//Выделение памяти для массива
		array = (int*)calloc(n, sizeof(int));
	else
		printf("Неправильно введённая операция! \n");

	//Заполнение массива вручную
	if (f == 1)
	{
		for (i = 0; i < n; i++)
			scanf_s("%d", &array[i]);
	}

	//Заполнение массива случайными числами
	if (f == 2)
	{
		for (i = 0; i < n; i++)
			array[i] = rand();
	}
	
	//Возвращение массива
	return array;
}

//Замена минимального элемента массива на средний.
int zum_sred(int* array, int n)
{
	//min_val - значение минимального элемента массива
	//sred_elem_mas - средний элемент массива
	//min_index - индекс минимального элемента массива
	int min_val, sred_elem_mas, min_index;
	
	//Находим средний элемент массива
	sred_elem_mas = (n-1)/2;

	//Находим минимальный элемент массива, его значение и индекс
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

	//Вывод обновлённого массива
	for (int i = 0; i < n; i++)
		printf("array[%d] = %d\n", i, array[i]);

	return 0;
}

// удалить все элементы где есть цифра X
int* delit(int* array, int n, int* s, char X)
{
	//arrayb - указательвведёный для создание массива
	int* arrayb = NULL;
	//Выделяем память для массив символов с максемальной длиной 20
	char* str = (char*)calloc(20, sizeof(char)); 
	*s = 0;

	for (int i = 0; i < n; i++)
	{
		// преобразуем элемент массива array в строку
		int sl = snprintf(str, sizeof str, "%d", array[i]); 


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
			//Увеличиваю количество элементов в новом массиве
			*s = *s + 1; 
			//Выделяем память на ещё один элемент в массиве
			arrayb = (int*)realloc(arrayb, *s * sizeof(int)); 
			//Записываем элемент в новый массив
			arrayb[*s - 1] = array[i]; 
		}
		
	}
	
	//освобождение памяти
	free(str);
	//возвращение массива
	return arrayb;
}

//Сформировать новый массив на основе существующего.
int* intmasb(int* array, int n)
{
	//Указатель на нолвый элемент массива
	int* arrayb = NULL;
	//Выделение памяти под новый массив
	arrayb = (int*)calloc(n, sizeof(int));

	//Заполнение нового массива
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 0)
			arrayb[i] = pow(array[i], 2);
		else
			arrayb[i] = 2 * array[i];
	}

	//Возвращение массива
	return arrayb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	//n - количество элементов массива
	//s - количество элементов нового массива
	int n, s; 

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

		//Освобождение памяти
		free(array);
		free(arraya);
		free(arrayb);
	}
	else
		printf("error");

	return 0;
}