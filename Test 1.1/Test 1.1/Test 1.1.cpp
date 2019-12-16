#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>


void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 2; j++)
		{
			if (array[j] > array[j + 2] && j % 2 != 0)
			{
				int help = array[j];
				array[j] = array[j + 2];
				array[j + 2] = help;
			}
		}
	}
}

void resultOfSort()
{
	int size = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &size);
	int* mass;
	mass = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		printf("Input the array elements: ");
		scanf_s("%d", &mass[i]);
	}
	bubbleSort(mass, size);
	printf("Sorted array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}
	free(mass);
}

bool test(int len, int arrayOfNumbers[], int sortedArray[])
{
	bubbleSort(arrayOfNumbers,len);
	for (int i = 0; i < len; ++i)
	{
		if (arrayOfNumbers[i] != sortedArray[i])
		{
			return false;
		}
	}
}

int main()
{
	int arrayFirst[] = { 5, 4, 3, 2, 1 };
	int sortedArrayFirst[] = { 5, 2, 3, 4, 1 };
	if (!test(5, arrayFirst, sortedArrayFirst))
	{
		printf("Error");
		return 1;
	}
	resultOfSort();
	return 0;
}