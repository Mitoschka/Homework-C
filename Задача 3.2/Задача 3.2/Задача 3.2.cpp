#include <stdlib.h>
#include <stdio.h>

void generationArray(int* array, int size)
{
	for (int i = 0; size > i; ++i)
	{
		array[i] = rand() % 20004 - 10000;
		printf("%d, ", array[i]);
	}
}

void qsortArray(int* supportingElement, int first, int last)
{
	if (first < last)
	{
		int left = first;
		int right = last;
		int middle = supportingElement[(left + right) / 2];
		do
		{
			while (supportingElement[left] < middle)
			{
				left++;
			}
			while (supportingElement[right] > middle)
			{
				right--;
			}
			if (left <= right)
			{
				int tmp = supportingElement[left];
				supportingElement[left] = supportingElement[right];
				supportingElement[right] = tmp;
				left++;
				right--;
			}
		} 
		while (left <= right);
		qsortArray(supportingElement, first, right);
		qsortArray(supportingElement, left, last);
	}
}

void arraySorting(int* array, int size)
{
	generationArray(array, size);
	qsortArray(array, 0, size - 1);
	printf("\n\nSorted array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int binarySearch(int a, int mass[], int supportElement)
{
	int high = 0;
	high = supportElement - 1;
	int low = 0;
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (a < mass[middle])
		{
			high = middle - 1;
		}
		else if (a > mass[middle])
		{
			low = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

int finding()
{
	int size = 0;
	int number = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int* array = new int[size];
	arraySorting(array, size);
	printf("\n\nEnter the desired element: ");
	scanf("%d", &number);
	int result = binarySearch(number, array, size);
	delete[] array;
	return result;
}

void resultOfFinding()
{
 	int position = finding();
	if (position != -1)
	{
		printf("\n\nThe element  found!\npostion: %d\n\n",position);
	}
	else
	{
		printf("\n\nThe element isn't found!\n\n");
	}
}

bool test(int len, int array[], int sortedArray[])
{
	qsortArray(array, 0, len - 1);
	for (int i = 0; i < len; ++i)
	{
		if (array[i] != sortedArray[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int arrayFirst[] = { 5, -2, 8, 0, 1 };
	int sortedArrayFirst[] = { -2, 0, 1, 5, 8 };
	if (!test(5, arrayFirst, sortedArrayFirst))
	{
		printf("Error");
		return 1;
	}
	const int length = 1000;

	int a[length]{};

	for (int i = 0; i < length; i++)
	{
		a[i] = 1;
	}

	int correctArray[length]{};

	for (int i = 0; i < length; i++)
	{
		correctArray[i] = 1;
	}

	qsortArray(a, 0, length - 1);
	if (!test(length, a, correctArray))
	{
		printf("Error");
		return 1;
	}
	resultOfFinding();
	resultOfFinding();
	return 0;
}