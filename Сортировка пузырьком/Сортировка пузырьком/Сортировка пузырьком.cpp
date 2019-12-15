#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int const N = 10;

void bubbleSort(int* num, int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		for (int j = (size - 1); j > i; j--)	// для всех элементов после i-ого
		{
			if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
			{
				int tmp = num[j - 1];	// меняем их местами
				num[j - 1] = num[j];
				num[j] = tmp;
			}
		}
	}
}

int main()
{
	int size = 0;
	printf("Enter the size of element: ");
	scanf("%d", &size);
	int num[N] = {};
	for (int i = 0; i < size; i++)
	{
		printf("\nEnter the %d element: ", i);
		scanf("%d", &num[i]);
	}
	printf("\nArray:");
	for (int i = 0; i < size; i++)
	{
		printf(" %d", num[i]);
	}
	bubbleSort(num, N);
	printf("\nSorted array:");
	for (int i = 0; i < size; i++)
	{
		printf(" %d", num[i]);
	}
	return 0;
}