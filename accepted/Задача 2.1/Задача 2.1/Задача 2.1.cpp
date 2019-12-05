#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int real(int numberOfIterative)
{
	int term = 1;
	int summand = 1;
	if (numberOfIterative <= 2)
	{
		return 1;
	}
	else
	{
		for (int i = 3; i <= numberOfIterative; i++)
		{
			const int sum = term + summand;
			term = summand;
			summand = sum;
		}
		return summand;
	}
}


int fibonacci(int num)
{
	if (num == 1 || num == 2)
	{
		return 1;
	}

	if (num <= 0)
	{
		return -1;
	}
	return fibonacci(num - 1) + fibonacci(num - 2);

}

bool test()
{
	return fibonacci(1) == 1 && fibonacci(5) == 5 && fibonacci(-5) == -1;
}

int main()
{
	if (!test())
	{
		printf("All is bad");
		return 0;
	}
	int numberOfRecurs = 0;
	printf(" Please enter the number up to 40: ");
	scanf("%d", &numberOfRecurs);
	for (int i = 1; i <= numberOfRecurs; i++)
	{
		printf(" %d  ", fibonacci(i));
	}
	int numberOfIterative = 0;
	printf("\n\n Please enter the number up to 800: ");
	scanf("%d", &numberOfIterative);
	int result = real(numberOfIterative);
	printf("%d", result);
	return 0;
}