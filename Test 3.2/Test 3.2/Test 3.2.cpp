#include "Sort.h"
#include <string.h>

void insertionSort(int countLeft, int countRight, int array[], int helpArray[])
{
	for (int i = countLeft; i <= countRight; i++)
	{
		const int value = array[i];
		const int helpValue = helpArray[i];
		int j = i;
		for (; j > countLeft && array[j - 1] > value; j--)
		{
			array[j] = array[j - 1];
			helpArray[j] = helpArray[j - 1];
		}
		array[j] = value;
		helpArray[j] = helpValue;
	}
}

void qsortForInt(int countLeft, int countRight, int array[], int helpArray[])
{
	auto value = array[(countLeft + countRight) / 2];
	for (int i = countLeft, j = countRight; i != j;)
	{
		if (array[i] > array[j])
		{
			int const currentValue = array[i];
			array[i] = array[j];
			array[j] = currentValue;

			int const helpCurrentValue = helpArray[i];
			helpArray[i] = helpArray[j];
			helpArray[j] = helpCurrentValue;
		}
		if (array[i] < value)
		{
			i++;
		}
		else
		{
			j--;
		}
		if (i == j)
		{
			if (countLeft - i + 1 < 10)
			{
				insertionSort(countLeft, i, array, helpArray);
			}
			else
			{
				qsortForInt(countLeft, i, array, helpArray);
			}
			if (j - countRight + 1 < 10)
			{
				insertionSort(j, countRight, array, helpArray);
			}
			else
			{
				qsortForInt(j, countRight, array, helpArray);
			}
		}
	}
}

void insertionSortForString(int countLeft, int countRight, char array[][30], int helpArray[])
{
	for (int i = countLeft; i <= countRight; i++)
	{
		auto value = array[i];
		const int helpValue = helpArray[i];
		int j = i;
		for (; j > countLeft && strcmp(array[j - 1], value) > 0; j--)
		{
			*array[j] = *array[j - 1];
			helpArray[j] = helpArray[j - 1];
		}
		*array[j] = *value;
		helpArray[j] = helpValue;
	}
}

void qsortForStrings(int countLeft, int countRight, char array[][30], int helpArray[])
{
	auto value = array[(countLeft + countRight) / 2];
	for (int i = countLeft, j = countRight; i != j;)
	{
		if (strcmp(array[i], array[j]) > 0)
		{
			auto currentValue = *array[i];
			*array[i] = *array[j];
			*array[j] = currentValue;

			int const helpCurrentValue = helpArray[i];
			helpArray[i] = helpArray[j];
			helpArray[j] = helpCurrentValue;
		}
		if (array[i] < value)
		{
			i++;
		}
		else
		{
			j--;
		}
		if (i == j)
		{
			if (countLeft - i + 1 < 10)
			{
				insertionSortForString(countLeft, i, array, helpArray);
			}
			else
			{
				qsortForStrings(countLeft, i, array, helpArray);
			}
			if (j - countRight + 1 < 10)
			{
				insertionSortForString(j, countRight, array, helpArray);
			}
			else
			{
				qsortForStrings(j, countRight, array, helpArray);
			}
		}
	}
}