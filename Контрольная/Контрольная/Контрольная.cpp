#include <stdio.h>

void shellSort(int maxSize, int intArray[])
{
	int inner = 0;
	int outer = 0;
	int valueToInsert = 0;
	int interval = 1;
	int elements = maxSize;
	int i = 0;
	while (interval <= elements / 3)  
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (outer = interval; outer < elements; outer++) 
		{
			valueToInsert = intArray[outer];
			inner = outer;
			while (inner > interval - 1 && intArray[inner - interval] >= valueToInsert)
			{
				intArray[inner] = intArray[inner - interval];
				inner -= interval;
			}
			intArray[inner] = valueToInsert;
		}
		interval = (interval - 1) / 3;
		i++;
	}
}

void methodShellSortStart()
{
	int cardinality = 0;
	int resFirst = 0;
	int resSecond = 0;
	printf("Enter number of elements: ");
	resFirst = scanf("%d", &cardinality);
	if (resFirst == 0 || resFirst == EOF || cardinality < 1)
	{
		printf("Enter valid data\n");
		return;
	}
	printf("\n");
	int* newMass = new int[cardinality]();
	for (int i = 0; i < cardinality; i++)
	{
		printf("Input %d element of array: ", i);
		resSecond = scanf("%d", &newMass[i]);
		if (resSecond == 0 || resSecond == EOF)
		{
			printf("Enter valid data\n");
			delete[] newMass;
			return;
		}
	}
	shellSort(cardinality, newMass);
	printf("\n");
	printf("Sorted array are:\n");
	for (int i = 0; i < cardinality; i++)
	{
		printf("%d ", newMass[i]);
	}
	delete[] newMass;
}

int main()
{
	methodShellSortStart();
	return 0;
}