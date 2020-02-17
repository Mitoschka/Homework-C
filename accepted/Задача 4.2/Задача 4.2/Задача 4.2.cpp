#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "myQSort.h"


const int maxSize = 100; // max длина массива

void printArray(int arrayOfNumbers[], int size) // вывод элементов массива на экран
{
	for (int i = 0; i != size; i++)
	{
		printf("%d\n", arrayOfNumbers[i]);
	}
}

int oftenElement(int arrayOfNumbers[], int size) // функция, возвращающая наиболее часто встречающийся элемент
{
	int counter = 0;
	int maxCounter = 0;
	int tempOftenElement = arrayOfNumbers[1];
	for (int i = 0; i != size - 1; ++i)
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

bool testQSort(int testArray[], int correctArray[], int size)
{
	qSortArray(testArray, 0, size - 1);
	for (int i = 0; i != size; ++i)
	{
		if (testArray[i] != correctArray[i])
		{
			return false;
		}
	}
	return true;
}

bool testOftenElement(int testArray[], int correctElement, int size)
{
	qSortArray(testArray, 0, size - 1);
	return oftenElement(testArray, size) == correctElement;
}

int main()
{
	int sortTestArray[] = { 0, 3, 4, 1, 2, 10, 9, 8, 11, 5, 12, 7, 6, 14, 13 };
	int sortTestCorrectArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	int testSize = 15;

	if (!testQSort(sortTestArray, sortTestCorrectArray, testSize))
	{
		printf("qsort test failed\n");
	}

	int oftenTestArray[] = { 0, 3, 3, 1, 2, 1, 2, 1, 1, 5, 12, 1, 3, 1, 13 };
	int correctOften = 1;

	if (!testOftenElement(oftenTestArray, correctOften, testSize))
	{
		printf("oftenElement test failed\n");
	}

	int arrayOfNumbers[maxSize];

	FILE* file;
	char nameFile[] = "numbers.txt";
	errno_t err = fopen_s(&file, nameFile, "r");
	if (err != 0)
	{
		printf("File doesnt exist\n");
		return 0;
	}
	int size = 0;
	fscanf_s(file, "%d", &size);

	for (int i = 0; i != size; ++i)
	{
		fscanf_s(file, "%d", &arrayOfNumbers[i]);
	}

	if (file)
	{
		err = fclose(file);
		if (err != 0)
		{
			printf("closing file error");
		}
	}

	delete file;

	printf("Array:\n");
	printArray(arrayOfNumbers, size);

	qSortArray(arrayOfNumbers, 0, size - 1);

	printf("The most often element: %d\n", oftenElement(arrayOfNumbers, size));

	return 0;
}