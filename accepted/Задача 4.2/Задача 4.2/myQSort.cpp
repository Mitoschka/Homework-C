#include "myQSort.h"

void insertSortArray(int arrayOfNumbers[], int first, int last) // алгоритм сортировки вставками
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

int partition(int arrayOfNumbers[], int first, int last) // функци€ нахождени€ разделител€
{
	int temporaryPivot = arrayOfNumbers[first]; // элемент, €вл€ющийс€ разделителем
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

void qSortArray(int arrayOfNumbers[], int first, int last) // алгоритм быстрой сортировки
{
	if (first >= last)
	{
		return;
	}
	if (last - first < 10) //						если элементов в куске массива меньше 10, то
	{
		insertSortArray(arrayOfNumbers, first, last);       // вызываем процедуру алгоритма вставками
	}
	else
	{
		int pivot = partition(arrayOfNumbers, first, last); // разделитель
		qSortArray(arrayOfNumbers, first, pivot - 1);
		qSortArray(arrayOfNumbers, pivot + 1, last);
	}
}