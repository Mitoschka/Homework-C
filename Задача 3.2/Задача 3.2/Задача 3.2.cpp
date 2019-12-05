#include <stdlib.h>
#include <stdio.h>

void generationArray(int* massif, int size)
{
	for (int i = 0; size > i; ++i)
	{
		massif[i] = rand() % 20004 - 10000;
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

int binarySearch(int a, int mass[], int n)
{
	int low = 0; 
	int high = 0; 
	int middle = 0;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (a < mass[middle])
			high = middle - 1;
		else if (a > mass[middle])
			low = middle + 1;
		else
			return middle;
	}
	return -1;
}

int finding()
{
	int size = 0;
	int number = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int* massif = new int[size];
	arraySorting(massif, size);
	printf("\n\nEnter the desired element: ");
	scanf("%d", &number);
	int result = binarySearch(number, massif, size);
	delete[] massif;
	return result;
}


void ResultOfFinding()
{
	int position = 0;
	position = finding();
	if (position != -1)
	{
		printf("\n\nThe element  found!\npostion: %d\n\n",position);
	}
	else
		printf("\n\nThe element isn't found!\n\n");
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
	ResultOfFinding();
	ResultOfFinding();
	return 0;
}