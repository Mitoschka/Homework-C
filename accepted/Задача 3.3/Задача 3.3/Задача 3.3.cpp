#include <iostream>
#include <time.h>
#include <stdlib.h>

// размер массива
const int sizeArray = 15;

// диапазон случайных чисел
const int randomNumberRange = 4;

// функция, которая принимает массив и заполняет его случайными значениями
void generationArray(int arrayOfNumbers[]) 
{
	for (int i = 0; i != sizeArray; i++)
	{
		arrayOfNumbers[i] = rand() % randomNumberRange;
	}
}

// вывод элементов массива на экран
void printArray(int arrayOfNumbers[]) 
{
	for (int i = 0; i != sizeArray; i++)
	{
		printf("%d\n", arrayOfNumbers[i]);
	}
}

// алгоритм сортировки вставками
void insertSortArray(int arrayOfNumbers[], int first, int last) 
{
	for (int i = first + 1; i != last + 1; ++i)
	{
		int j = i;
		while (j > 1 && arrayOfNumbers[j] < arrayOfNumbers[j - 1])
		{
			int temp = arrayOfNumbers[j];
			arrayOfNumbers[j] = arrayOfNumbers[j - 1];
			arrayOfNumbers[j - 1] = temp;
			--j;
		}
	}

}

// функция нахождения разделителя
int partition(int arrayOfNumbers[], int first, int last) 
{
	// элемент, являющийся разделителем
	int temporaryPivot = arrayOfNumbers[first]; 
	int i = first;
	int j = i;
	for (i = first + 1; i != last + 1; ++i)
	{
		if (arrayOfNumbers[i] <= temporaryPivot)
		{
			++j;
			int temp = arrayOfNumbers[j];
			arrayOfNumbers[j] = arrayOfNumbers[i];
			arrayOfNumbers[i] = temp;
		}
	}
	int temp = arrayOfNumbers[first];
	arrayOfNumbers[first] = arrayOfNumbers[j];
	arrayOfNumbers[j] = temp;
	return j;
}

// алгоритм быстрой сортировки
void qSortArray(int arrayOfNumbers[], int first, int last) 
{
	if (first >= last)
	{
		return;
	}
	// если элементов в куске массива меньше 10, то
	if (last - first < 10) 
	{
		// вызываем процедуру алгоритма вставками
		insertSortArray(arrayOfNumbers, first, last); 
	}
	else
	{
		// разделитель
		int pivot = partition(arrayOfNumbers, first, last); 
		qSortArray(arrayOfNumbers, first, pivot - 1);
		qSortArray(arrayOfNumbers, pivot + 1, last);
	}
}

// функция, возвращающая наиболее часто встречающийся элемент
int mostCommonElement(int arrayOfNumbers[]) 
{
	int counter = 0;
	int maxCounter = 0;
	int tempOftenElement = arrayOfNumbers[1];
	for (int i = 0; i != sizeArray - 1; ++i)
	{
		if (arrayOfNumbers[i] == arrayOfNumbers[i + 1])
		{
			++counter;
		}
		else
		{
			if (counter > maxCounter)
			{
				maxCounter = counter;
				tempOftenElement = arrayOfNumbers[i];
			}
			counter = 0;
		}
	}
	return tempOftenElement;
}

bool testQSort(int testArray[], int correctArray[])
{
	qSortArray(testArray, 0, sizeArray - 1);
	for (int i = 0; i != sizeArray; ++i)
	{
		if (testArray[i] != correctArray[i])
		{
			return false;
		}
	}
	return true;
}

bool testOftenElement(int testArray[], int correctElement)
{
	qSortArray(testArray, 0, sizeArray - 1);
	return mostCommonElement(testArray) == correctElement;
}

int main()
{
	int sortTestArray[] = { 0, 3, 4, 1, 2, 10, 9, 8, 11, 5, 12, 7, 6, 14, 13 };
	int sortTestCorrectArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	if (!testQSort(sortTestArray, sortTestCorrectArray))
	{
		printf("qsort test failed\n");
	}

	int oftenTestArray[] = { 0, 3, 3, 1, 2, 1, 2, 1, 1, 5, 12, 1, 3, 1, 13 };
	int correctOften = 1;

	if (!testOftenElement(oftenTestArray, correctOften))
	{
		printf("mostCommonElement test failed");
	}

	int arrayOfNumbers[sizeArray]{};

	printf("Array:\n");
	generationArray(arrayOfNumbers);
	printArray(arrayOfNumbers);

	qSortArray(arrayOfNumbers, 0, sizeArray - 1);

	printf("The most often element: %d\n", mostCommonElement(arrayOfNumbers));

	return 0;
}