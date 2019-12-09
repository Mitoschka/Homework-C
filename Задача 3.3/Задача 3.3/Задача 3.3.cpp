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

void qsortArray(int* sArr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = sArr[(left + right) / 2];
		do
		{
			while (sArr[left] < middle) left++;
			while (sArr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = sArr[left];
				sArr[left] = sArr[right];
				sArr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qsortArray(sArr, first, right);
		qsortArray(sArr, left, last);
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

void differentiationOfNumber()
{
	int size = 0;
	int number = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int* firstMassif = new int[size];
	arraySorting(firstMassif, size);
	int* secondMassif = new int[size];
	for (int i = 1; i < size; i++)
	{
		secondMassif[i] = firstMassif[i] - firstMassif[i - 1];
	}
	secondMassif[0] = firstMassif[0];

	bool flag = false;
	int maxLen = 0;
	int maxIndex = 0;
	int len = 0;
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (secondMassif[i] == 0 && flag)
		{
			len++;
			continue;
		}
		if (secondMassif[i] == 0)
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
	printf("\n%d\n", firstMassif[maxIndex]);
	delete[] firstMassif;
	delete[] secondMassif;
}

void printDifferentiationOfNumber()
{

}

bool test(int len, int massif[], int sortedArray[])
{
	qsortArray(massif, 0, len - 1);
	for (int i = 0; i < len; ++i)
	{
		if (massif[i] != sortedArray[i])
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
	differentiationOfNumber();
	return 0;
}