#include <stdlib.h>
#include <stdio.h>

void generationArray(int* massif, int size)
{
	for (int i = 0; size > i; ++i)
	{
		massif[i] = rand() % 10 - 5;
	}
}

void printArray(int* array, int size)
{
	for (int i = 0; size > i; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("\n\n");
}

int maxUnicElement(int* unicElements, int* unicElemsCounts, int size) 
{
	int maxElemnt = -100000000;
	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (maxElemnt < unicElemsCounts[i])
		{
			maxElemnt = unicElemsCounts[i];
			maxIndex = i;
		}
	}
	return unicElements[maxIndex];
}

int matchRate(int* arrayOfElements, int* arrayOfUniqueElements, int* arrayOfRepetitionsOfElements, int size)
{
	int unic = 0;
	for (int i = 0; i < size; i++)
	{
		int element = arrayOfElements[i];
		bool isUnic = true;
		for (int j = 0; j < unic; j++)
		{
			if (arrayOfUniqueElements[j] == element)
			{
				isUnic = false;
				arrayOfRepetitionsOfElements[j] += 1;
				break;
			}
		}
		if (isUnic)
		{
			arrayOfUniqueElements[unic] = element;
			arrayOfRepetitionsOfElements[unic] = 1;
			unic++;
		}
	}
	return unic;
}

bool test(int* arrayOfElements, int size, int unic, int unicElement)
{
	int* arrayOfUniqueElements = new int[size]();
	int* arrayOfRepetitionsOfElements = new int[size]();
	if (unic != matchRate(arrayOfElements, arrayOfUniqueElements, arrayOfRepetitionsOfElements, size))
	{
		delete[] arrayOfUniqueElements;
		delete[] arrayOfRepetitionsOfElements;
		return false;
	}
	if (unicElement != maxUnicElement(arrayOfUniqueElements, arrayOfRepetitionsOfElements, unic))
	{
		delete[] arrayOfUniqueElements;
		delete[] arrayOfRepetitionsOfElements;
		return false;
	}
	delete[] arrayOfUniqueElements;
	delete[] arrayOfRepetitionsOfElements;
	return true;
}

int main()
{
	int arrayOfElementsTest[] = {1, 3, 5, 1, 4, 2, 1, 4};
	if (!test(arrayOfElementsTest, 8, 5, 1))
	{
		printf("Error");
		return 1;
	}
	int size = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int* arrayOfElements = new int[size];
	int* arrayOfUniqueElements = new int[size]();
	int* arrayOfRepetitionsOfElements = new int[size]();
	generationArray(arrayOfElements, size);
	printArray(arrayOfElements, size);
	int unicNumbers = matchRate(arrayOfElements, arrayOfUniqueElements, arrayOfRepetitionsOfElements, size);
	printArray(arrayOfUniqueElements, unicNumbers);
	printArray(arrayOfRepetitionsOfElements, unicNumbers);
	printf("most common elment: %d", maxUnicElement(arrayOfUniqueElements, arrayOfRepetitionsOfElements, unicNumbers));
	delete[] arrayOfElements;
	delete[] arrayOfUniqueElements;
	delete[] arrayOfRepetitionsOfElements;
	return 0;
}