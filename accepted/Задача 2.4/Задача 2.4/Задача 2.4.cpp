#include <stdlib.h>
#include <stdio.h>
#include <time.h>  

void magicSort(int* mass, int number)
{
	int countMin = 0; 
	int countMax = 0;
	int element = mass[0];
	for (int i = 1; i < number; i++)
	{
		if (element <= mass[i])
		{
			countMax++;
		}
		else
		{
			countMin++;
		}
	}
	for (int i = 1; i <= countMin; i++)
	{
		mass[i - 1] = mass[i];
	}
	mass[countMin] = element;
	int j = countMin + 1;
	for (int i = 0; i < countMin; i++)
	{
		if (mass[i] >= element)
		{
			for (j; j < number; j++)
			{
				if (mass[j] < element)
				{
					int a = mass[j];
					mass[j] = mass[i];
					mass[i] = a;
					break;
				}
			}
		}	
	}
}

void resultOfSorted()
{
	printf("Enter the size of the array: ");
	int number = 0;
	scanf("%d", &number);
	int* massif = new int [number];
	for (int i = 0; number > i; ++i)
	{
		massif[i] = rand() % 20004 - 10000;
		printf("%d, ", massif[i]);
	}
	printf("\nSorted array:\n");
	magicSort(massif, number);
	for (int i = 0; i < number; i++)
	{
		printf("%d, ", massif[i]);
	}
	delete[] massif;
}
bool test(int len,  int mass[])
{
	int element = mass[0];
	magicSort(mass, len);
	bool checFlag = true;
	for (int i = 0; i < len; ++i)
	{
		if (element > mass[i] && checFlag)
		{
			continue;
		}
		if (element == mass[i])
		{
			checFlag = false;
			continue;
		}
		if (element <= mass[i] && !checFlag)
		{
			continue;
		}
		return false;
	}
	return true;
}

int main()
{
	int elementFirst = 5;
	int massifFirst[] = { 0, 1, 5, 7, 9 };
	if (!test(5, massifFirst))
	{
		printf("Error");
		return 1;
	}
	int elementSecond = 0;
	int massifSecond[] = { -1214, -50, 0, 1482, 9581 };
	if (!test(5, massifSecond))
	{
		printf("Error");
		return 1;
	}
	srand(time(nullptr));
	resultOfSorted();
	return 0;
}