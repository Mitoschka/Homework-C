#include <iostream>
#include <ctime>
#include <cstdlib>

// размер массива
const int sizeArray = 7;
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

// функция нахождения разделителя
int partition(int arrayOfNumbers[], int first, int last)
{
	int temp = 0;
	int marker = first;
	for (int i = first; i <= last; i++)
	{
		if (arrayOfNumbers[i] < arrayOfNumbers[last])
		{
			temp = arrayOfNumbers[marker];
			arrayOfNumbers[marker] = arrayOfNumbers[i];
			arrayOfNumbers[i] = temp;
			marker += 1;
		}
	}
	temp = arrayOfNumbers[marker];
	arrayOfNumbers[marker] = arrayOfNumbers[last];
	arrayOfNumbers[last] = temp;
	return marker;
}

// алгоритм быстрой сортировки
void qSortArray(int arrayOfNumbers[], int first, int last)
{
	if (first >= last)
	{
		return;
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
	int tempCommonElement = arrayOfNumbers[0];
	for (int i = 0; i != sizeArray; ++i)
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
				tempCommonElement = arrayOfNumbers[i];
			}
			counter = 0;
		}
	}
	return tempCommonElement;
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

bool testCommonElement(int testArray[], int correctElement)
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

	if (!testCommonElement(oftenTestArray, correctOften))
	{
		printf("oftenElement test failed");
	}

	int arrayOfNumbers[sizeArray]{};

	srand(time(nullptr));

	printf("Array:\n");
	generationArray(arrayOfNumbers);
	printArray(arrayOfNumbers);

	qSortArray(arrayOfNumbers, 0, sizeArray - 1);

	printf("The most common element: %d\n", mostCommonElement(arrayOfNumbers));

	return 0;
}