#include "Sort.h"
#include <string.h>

void insertionSort(int countLeft, int countRight, int intArray[], char stringArray[][30], int helpArray[], bool isIntSort)
{
	for (int i = countLeft; i <= countRight; i++)
	{
		const int intValue = intArray[i];
		auto stringValue = stringArray[i];
		const int helpValue = helpArray[i];
		int j = i;
		bool isValueGreater = true;
		if (isIntSort)
		{
			isValueGreater = intArray[j - 1] > intValue;
		}
		else
		{
			strcmp(stringArray[j - 1], stringValue) > 0;
		}
		for (; j > countLeft && isValueGreater; j--)
		{
			if (isIntSort)
			{
				intArray[j] = intArray[j - 1];
			}
			else
			{
				
				*stringArray[j] = *stringArray[j - 1];
			}
			helpArray[j] = helpArray[j - 1];
			if (isIntSort)
			{
				isValueGreater = intArray[j - 1] > intValue;
			}
			else
			{
				strcmp(stringArray[j - 1], stringValue) > 0;
			}
		}
		if (isIntSort)
		{
			helpArray[j] = helpValue;
		}
		else
		{
			*stringArray[j] = *stringValue;
		}
	}
}

void qsort(int countLeft, int countRight, int intArray[], char stringArray[][30], int helpArray[], bool isIntSort)
{
	auto intValue = intArray[(countLeft + countRight) / 2];
	auto stringValue = stringArray[(countLeft + countRight) / 2];
	bool isGreater = true;
	for (int i = countLeft, j = countRight; i != j;)
	{
		if (isIntSort)
		{
			isGreater = intArray[i] > intArray[j];
		}
		else
		{
			isGreater = strcmp(stringArray[i], stringArray[j]) > 0;
		}
		if (isGreater)
		{
			if (isIntSort)
			{
				int const currentValue = intArray[i];
				intArray[i] = intArray[j];
				intArray[j] = currentValue;
			}
			else
			{
				auto currentValue = *stringArray[i];
				*stringArray[i] = *stringArray[j];
				*stringArray[j] = currentValue;
			}

			int const helpCurrentValue = helpArray[i];
			helpArray[i] = helpArray[j];
			helpArray[j] = helpCurrentValue;
		}
		bool isSmaller = true;
		if (isIntSort)
		{
			isSmaller = intArray[i] < intValue;
		}
		else
		{
			isSmaller = stringArray[i] < stringValue;
		}
		if (isSmaller)
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
				insertionSort(countLeft, i, intArray, stringArray, helpArray, isIntSort);
			}
			else
			{
				qsort(countLeft, i, intArray, stringArray, helpArray, isIntSort);
			}
			if (j - countRight + 1 < 10)
			{
				insertionSort(j, countRight, intArray, stringArray, helpArray, isIntSort);
			}
			else
			{
				qsort(j, countRight, intArray, stringArray, helpArray, isIntSort);
			}
		}
	}
}
