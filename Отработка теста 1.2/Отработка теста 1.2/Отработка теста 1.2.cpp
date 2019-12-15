#include <iostream>
#include <stdio.h>

int const N = 100;

void input(FILE* file)
{
	char arr[N] = "";
	file = fopen("test.txt", "w");
	printf("Enter the string: ");
	scanf("%s", &arr);
	fprintf(file, "%s%s","The string: ", arr);
	fclose(file);
}

void output(FILE* file, char arr[])
{
	file = fopen("test.txt", "r");
	while (fgets(arr, N, file) != nullptr)
	{
		printf("\n%s\n", arr);
	}
	fclose(file);
}

void matchRate(int* arrayOfElements, int* arrayOfUniqueElements, int* arrayOfRepetitionsOfElements, int size)
{
	for (int i = 0; i < size; i++)
	{
		int element = arrayOfElements[i];
		for (int j = 0; j < size; j++)
		{
			if (arrayOfUniqueElements[j] == element)
			{
				arrayOfRepetitionsOfElements[j] += 1;
			}
		}
	}
}

void result(FILE* file, char arr[])
{
	int* arrayOfElements = {};
	int* arrayOfUniqueElements = {};
	int* arrayOfRepetitionsOfElements = {};
	int size = 0;
	file = fopen("test.txt", "r");
	matchRate(arrayOfElements, arrayOfUniqueElements, arrayOfRepetitionsOfElements, size);
	printf("Result: %d", arrayOfRepetitionsOfElements);
}

int main(FILE* file)
{
	char arr[N];
	input(file);
	output(file, arr);
	result(file, arr);
	return 0;
}