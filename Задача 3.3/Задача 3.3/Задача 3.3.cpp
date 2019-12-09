#include <stdlib.h>
#include <stdio.h>

void generationArray(int* massif, int size)
{
	for (int i = 0; size > i; ++i)
	{
		massif[i] = rand() % 10 - 5;
		printf("%d, ", massif[i]);
	}
}

void qsortArray(int* supportingElement, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = supportingElement[(left + right) / 2];
		do
		{
			while (supportingElement[left] < middle) left++;
			while (supportingElement[right] > middle) right--;
			if (left <= right)
			{
				int tmp = supportingElement[left];
				supportingElement[left] = supportingElement[right];
				supportingElement[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qsortArray(supportingElement, first, right);
		qsortArray(supportingElement, left, last);
	}
}

void arraySorting(int* massif, int size)
{
	generationArray(massif, size);
	qsortArray(massif, 0, size - 1);
	printf("\n\nSorted array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", massif[i]);
	}
}

int differentiationOfNumber(int* firstArray, int size)
{
	int* secondArray = new int[size];
	for (int i = 1; i < size; i++)
	{
		secondArray[i] = firstArray[i] - firstArray[i - 1];
	}
	secondArray[0] = firstArray[0];

	bool flag = false;
	int maxLen = 0;
	int maxIndex = 0;
	int len = 0;
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (secondArray[i] == 0 && flag)
		{
			len++;
			continue;
		}
		if (secondArray[i] == 0)
		{
			len++;
			index = i;
			flag = true;
		}
		else
		{
			if (maxLen <= len)
			{
				maxLen = len;
				maxIndex = index;
			}
			len = 0;
			flag = false;
		}
	}
	delete[] secondArray;
	return firstArray[maxIndex];
}

void  printDifferentiationOfNumber()
{
	int size = 0;
	int number = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int* firstArray = new int[size];
	arraySorting(firstArray, size);
	differentiationOfNumber(firstArray, size);
	printf("\n%d\n", differentiationOfNumber(firstArray, size));
	delete[] firstArray;
}

bool differentiationTest(int* firstArray, int secondArray, int size)
{
	differentiationOfNumber(firstArray, size);
	int result = differentiationOfNumber(firstArray, size);
	return result == secondArray;
}

bool sortTest(int len, int array[], int sortedArray[])
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
	int  differentiationTestArray[] = { -4, -3, 0, 1, 1, 1, -5, -5, -4, 1 };
	int maxIndex = 1;
	if (!differentiationTest(differentiationTestArray, maxIndex, 10))
	{
		printf("error");
		return 1;
	}

	int arrayFirstTest[] = { 5, -2, 8, 0, 1 };
	int sortedArrayFirst[] = { -2, 0, 1, 5, 8 };
	if (!sortTest(5, arrayFirstTest, sortedArrayFirst))
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
	if (!sortTest(length, a, correctArray))
	{
		printf("Error");
		return 1;
	}
	printDifferentiationOfNumber();
	return 0;
}