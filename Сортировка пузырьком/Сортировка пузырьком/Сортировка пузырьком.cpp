#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

void input() {};

void printArray() {};

void bubbleSort() {};

void printSortedArray() {};

void input(int* arrayOfElements, int size)
{
	printf("Enter the size of element: ");
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		printf("\nEnter the %d element: ", i);
		scanf("%d", &arrayOfElements[i]);
	}
}

void printArray(int* arrayOfElements, int size)
{
	printf("\nArray:");
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arrayOfElements[i]);
	}
	printf("\n");
}

void printSortedArray(int *arrayOfElements, int size)
{
	printf("\nSorted array:");
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arrayOfElements[i]);
	}
	printf("\n");
}

void swap(int* firstNumber, int* secondNumber)
{
	int temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}
 
void bubbleSort(int arrayOfElements[], int number)
{
	bool swapped = true;
	for (int i = 0; i < number - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < number - i - 1; j++)
		{
			if (arrayOfElements[j] > arrayOfElements[j + 1])
			{
				swap(&arrayOfElements[j], &arrayOfElements[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}

int main()
{
	int size = 0;
	int arrayOfElements[] = {0};
	int number = sizeof(arrayOfElements) / sizeof(arrayOfElements[0]);
	input(arrayOfElements, number);
	printArray(arrayOfElements, size);
	bubbleSort(arrayOfElements, number);
	printSortedArray(arrayOfElements, size);
	return 0;
}