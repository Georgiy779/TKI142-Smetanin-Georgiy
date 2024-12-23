#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>
#include <time.h> // чтобы использовать  функцию  time()


int* intmas(int n)
{
	//Для работы  раномайзера
	srand(time(NULL));

	//f - переменная введённая для  определение способа ввода элементов
	//i - индекс элемента массива
	int f, i;
	//array - указатель на массив
	int* array = NULL;

	//Определение способа ввода массива
	printf("1 - keybord\n2 - random\n");
	scanf_s("%d", &f);
	printf("   -> %d\n\n", f);

	//Проверка правильности ввода переменной f
	if (f == 1 || f == 2)
		//Выделение памяти для массива
		array = (int*)calloc(n, sizeof(int));
	else
		printf("Неправильно введённая операция! \n");

	//Заполнение массива с клавиатуры
	if (f == 1)
	{
		for (i = 0; i < n; i++)
			scanf_s("%d", &array[i]);
	}

	//Заполнение массива случайными значениями
	if (f == 2)
	{
		for (i = 0; i < n; i++)
			array[i] = rand();
	}

	//Возвращение массива
	return array;
}

//Сумма отрицательных элементов массива кратных 10
int sumkrat(int* array, int n)
{
	//sum - сумма злементов
	int sum = 0;
	//Проверка на кратность 10 и отрицательность
	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0 && array[i] % 10 == 0)
		{
			sum = sum + array[i];
		}
	}

	//Вывод суммы
	printf("sum = %d\n", sum);
	return 0;
}

//Заменить первые k элементов массива в обратном порядке
int zam(int* array, int n)
{
	//k - переменная обозначающая какое количество первых элемнтов должно быть записанно в обратном порядке
	//с - переменная введённая для записи первых k элементов массива в обратном порядке
	int c, k;
	//Ввод переменной k
	printf("input k\n");
	scanf_s("%d", &k);
	k--;
	printf("   -> %d\n\n", k);
	//запись первых k элементов в обратном порядке
	for (int i = 0; i < k; i++)
	{
		c = array[i];
		array[i] = array[k];
		array[k] = c;
		k = k - 1;
	}
	return 0;
}

//Определение пары элементов произведение которых равных заданному числу.
int com(int* array, int n)
{
	//f - заданное число
	int f;
	//Ввод переменной f
	printf("input f\n");
	scanf_s("%d", &f);
	//Определение подходящей пары чисел
	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] * array[i + 1] == f)
		{
			printf(" array[%d] = %d and array[%d] = %d\n", i, array[i], i + 1, array[i + 1]);
		}
		else
			printf("Таких элементов нет.\n");
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	//n - количество элементов массива
	//sum - Сумма элементов массива
	int n, sum; 

	//Ввод количества элемнтов массива
	printf("input n\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);

	//Создание массива
	int* array = intmas(n);

	//проверка на правильный ввод массива
	if (array != NULL)
	{
		//Вывод массива
		for (int i = 0; i < n; i++)
		{
			printf("array[%d] = %d\n", i, array[i]);
		}

		//Сумма отрицательных элементов массива кратных 10
		sumkrat(array, n);

		//Заменить первые k элементов массива в обратном порядке
		zam(array, n);
		for (int i = 0; i < n; i++)
		{
			printf("array[%d] = %d\n", i, array[i]);
		}

		//Определение пары элементов произведение которых равных заданному числу.
		com(array, n);

		//Освобождение памяти
		free(array);
	}
	else
		printf("error");

	return 0;
}