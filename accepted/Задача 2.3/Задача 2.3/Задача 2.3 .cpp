#include <stdio.h>
#include <malloc.h>
#include <limits.h>

const int elementOfCountBase = 100000000;

void methodBubbleSort(int cardinality, int mass[])
{
	bool noSwap = false;

	for (int i = cardinality - 1; i >= 0; i--)
	{
		noSwap = true;
		for (int j = 0; j < i; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				int tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
				noSwap = false;
			}
		}
		if (noSwap)
		{
			break;
		}
	}
}

void countingSort(int mass[], int result[], int number)
{
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < number; i++)
	{
		if (min > mass[i])
		{
			min = mass[i];
		}
		if (max < mass[i])
		{
			max = mass[i];
		}
	}
	int* count = new int [max - min + 1]();
	for (int i = 0; i < number; ++i)
	{
		count[mass[i] - min] += 1;
	}
	int element = 0;
	for (int i = 0; i <= max - min; ++i)
	{
		for (int j = 1; j <= count[i]; ++j)
		{
			result[element] = i + min;
			element++;
		}
	}
	delete[] count;
}

void methodCountingSortStart()
{
	int numberOfElements = 0;
	printf("Enter number of elements: ");
	scanf("%d", &numberOfElements);
	int* massSize = new int[numberOfElements]();
	for (int i = 0; i < numberOfElements; ++i)
	{
		printf("Enter next elements: ");
		scanf("%d", &massSize[i]);
	}
	int* sortedArray = new int[numberOfElements]();
	countingSort(massSize, sortedArray, numberOfElements);
	printf("Sorted array are:\n");
	for (int i = 0; i < numberOfElements;i++)
	{
		printf("%d ", sortedArray[i]);
	}
	delete[] sortedArray;
	delete[] massSize;
}

void methodBubleSortStart()
{
	int cardinality = 0;
	printf("\nEnter number of elements: ");
	scanf("%d", &cardinality);

	int* newMass = new int [cardinality]();
	for (int i = 0; i < cardinality; i++)
	{
		printf("Input next element of array: ");
		scanf_s("%d", &newMass[i]);
	}
	methodBubbleSort(cardinality, newMass);

	printf("Sorted array are:\n");
	for (int i = 0; i < cardinality; i++)
	{
		printf("%d ", newMass[i]);
	}
	delete[] newMass;
}

bool test(int len, int arrayOfElements[], int sortedArray[])
{
	int* res = new int [len]();
	countingSort(arrayOfElements, res, len);
	for (int i = 0; i < len; ++i)
	{
		if (res[i] != sortedArray[i])
		{
			delete[] res;
			return false;
		}

	}
	methodBubbleSort(len, arrayOfElements);
	for (int i = 0; i < len; ++i)
	{
		if (arrayOfElements[i] != sortedArray[i])
		{
			delete[] res;
			return false;

		}
	}
	delete[] res;
	return true;
}

int main()
{
	int arrayFirst[] = {5, -2, 8, 0, 1};
	int sortedArrayFirst[] = {-2, 0, 1, 5, 8};
	if (!test(5, arrayFirst, sortedArrayFirst))
	{
		printf("Error");
		return 1;
	}
	int arraySecond[] = {1, 1, -1, 1, 1};
	int	sortedArraySecond[] = {-1, 1, 1, 1, 1};
	if (!test(5, arraySecond, sortedArraySecond))
	{
		printf("Error");
		return 1;
	}
	int arrayThird[] = {1000000, 1000000, -1000000, 1000000, 1000000};
	int	sortedArrayThird[] = {-1000000, 1000000, 1000000, 1000000, 1000000};
	if (!test(5, arrayThird, sortedArrayThird))
	{
		printf("Error");
		return 1;
	}

	methodCountingSortStart();
	methodBubleSortStart();
	return 0;
}