#include <iostream>
#include <stdio.h>

int logPow(int degLog, int numLog)
{
	if (degLog == 0)
	{
		return 1;
	}
	if (numLog == 0)
	{
		return 0;
	}
	int resultLogPow = 1;
	while (degLog)
	{
		if (degLog & 1)
		{
			resultLogPow *= numLog;
		}
		numLog *= numLog;
		degLog >>= 1;

	}
	return resultLogPow;
}

int linePow(int deg, int num)
{
	if (num == 0)
	{
		return 0;
	}
	int resultLinePow = 1;
	for (int i = 0; i < deg; ++i)
	{
		resultLinePow = resultLinePow * num;
	}
	return resultLinePow;
}


int main()
{
	int num = 0;
	printf("Enter a number at least 0: ");
	scanf("%d", &num);

	int deg = 0;
	printf("Enter the degree of the number: ");
	scanf("%d", &deg);

	int resultLinePow = linePow(deg, num);
	printf("\nResult = %d", resultLinePow);

	int numLog = 0;
	printf("\n\nEnter a number at least 0: ");
	scanf("%d", &numLog);

	int degLog = 0;
	printf("Enter the degree of the number: ");
	scanf("%d", &degLog);

	int resultLogPow = logPow(degLog, numLog);
	printf("\nResult = %d", resultLogPow);
	return 0;
}

