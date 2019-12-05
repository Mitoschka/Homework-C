#include <stdio.h>

int const N = 100000000;

void insertionSort(int left, int right, int arrayOfNumbers[])
{
	for (int i = left; i <= right; i++)
	{
		int temp = arrayOfNumbers[i];
		for (int j = i - 1; j >= left; j--)
		{
			if (arrayOfNumbers[j] < temp)
			{
				break;
			}

			arrayOfNumbers[j + 1] = arrayOfNumbers[j];
			arrayOfNumbers[j] = temp;
		}
	}

}

void quickSort(int* arrayOfNumbers, int left, int right)
{
	int leftHold = left;
	int rightHold = right;
	int pivot = arrayOfNumbers[left];
	while (left < right)
	{
		while ((arrayOfNumbers[right] >= pivot) && (left < right))
		{
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		}
		if (left != right) // если границы не сомкнулись
		{
			arrayOfNumbers[left] = arrayOfNumbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо 
		}
		while ((arrayOfNumbers[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			arrayOfNumbers[right] = arrayOfNumbers[left];
			right--;
		}
	}
	arrayOfNumbers[left] = pivot;
	pivot = left;
	left = leftHold;
	right = rightHold;
	if (left < pivot)
	{
		if (left < 10)
		{
			insertionSort(left, pivot, arrayOfNumbers);
		}
		quickSort(arrayOfNumbers, left, pivot - 1);
	}
	if (right > pivot)
	{
		if (right < 10)
		{
			insertionSort(right, pivot, arrayOfNumbers);
		}
		quickSort(arrayOfNumbers, right, pivot + 1);
	}
}

void resultOfSort()
{
	int num = 0;
	printf("Enter the size of numbers elements: ");
	scanf("%d", &num);
	int* arrayOfElements = new int[N] {};
	for (int i = 0; i < num; i++)
	{
		printf("Enter the numbers: ");
		scanf(" %d,", &arrayOfElements[i]);
	}
	quickSort(arrayOfElements, 0, num - 1);
	for (int i = 0; i < num; i++)
	{
		printf(" %4d ", arrayOfElements[i]);
	}
	printf("\n\n");

	delete[] arrayOfElements;
}

bool test(int len, int arrayOfNumbers[], int sortedArray[])
{
	insertionSort(0, len - 1, arrayOfNumbers);
	for (int i = 0; i < len; ++i)
	{
		if (arrayOfNumbers[i] != sortedArray[i])
		{
			return false;
		}

	}
	quickSort(arrayOfNumbers, 0, len - 1);
	for (int i = 0; i < len; ++i)
	{
		if (arrayOfNumbers[i] != sortedArray[i])
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
	int arraySecond[] = { 1, 1, -1, 1, 1 };
	int	sortedArraySecond[] = { -1, 1, 1, 1, 1 };
	if (!test(5, arraySecond, sortedArraySecond))
	{
		printf("Error");
		return 1;
	}
	int arrayThird[] = { 1000000, 1000000, -1000000, 1000000, 1000000 };
	int	sortedArrayThird[] = { -1000000, 1000000, 1000000, 1000000, 1000000 };
	if (!test(5, arrayThird, sortedArrayThird))
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

	quickSort(a, 0, length - 1);
	if (!test(length, a, correctArray))
	{
		printf("Error");
		return 1;
	}
	
	//int	sortedArrayFour[5] = {10000};
	//if (!test(5, arrayThird, sortedArrayFour))
	//{
	//	printf("Error");
	//	return 1;
	//}
	resultOfSort();
	return 0;
}