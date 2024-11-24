#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

int* intmas(int n)
{
	int f, i;
	int* array = NULL;
	
	printf("1 - keybord\n2 - random\n");
	scanf_s("%d", &f);
	printf("   -> %d\n\n", f);

	if(f==1 || f==2)
		array = (int*)calloc(n, sizeof(int));

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
	int n; // количество элементов массива

	printf("input n\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);

	int* array =  intmas(n);
	
	if (array != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			printf("array[%d] = %d\n", i, array[i]);
		}
	}
	else
		printf("error");


	return 0;
}