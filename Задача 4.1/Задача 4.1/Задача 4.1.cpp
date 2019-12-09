#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int size = sizeof(int);

int abs(int x)
{
	return x >= 0 ? x : -x;
}

void showBinaryNumber(int* bin)
{
	printf("В двоичной системе: ");
	for (int i = size - 1; i >= 0; i--)
	{
		printf("%d", bin[i]);
	}
	printf("\n");
}

void makeBinary(int binaryNum, int* res)
{
	bool isNegative = binaryNum < 0;
	for (int i = 0; i < size; i++)
	{
		res[i] = (binaryNum >> i) & 1;
	}
}

int makeDecimal(int* bin)
{
	bool isNegative = bin[size - 1] == 1;
	if (isNegative)
	{
		int deductible = 1;
		for (int i = 0; i < size; i++)
		{
			bin[i] = (bin[i] - deductible) & 1;
			if (bin[i] == 0)
			{
				deductible = 0;
			}
		}
		for (int i = size - 1; i >= 0; i--)
		{
			bin[i] = 1 - bin[i];
		}
	}
	int res = 0;
	int powerTwo[size] = { 1 };
	for (int i = 1; i < size; i++)
	{
		powerTwo[i] = powerTwo[i - 1] * 2;
	}
	for (int i = 0; i < size; i++)
	{
		res += powerTwo[i] * bin[i];
	}
	res = isNegative ? -res : res;
	return res;
 }

void enterNumber(int* binaryNum)
{
	int num = 0;
	printf("Введите целое десятичное число: ");
	scanf("%d", &num);
	makeBinary(num, binaryNum);
	showBinaryNumber(binaryNum);
}

void binarySum(int* binaryNum1, int* binaryNum2, int* res)
{
	int addition = 0;
	for (int i = 0; i < size; i++)
	{
		res[i] = (binaryNum1[i] + binaryNum2[i] + addition) & 1;
		if (res[i] == 0 && binaryNum1[i] + binaryNum2[i] + addition != 0)
		{
			addition = 1;
		}
		else
		{
			addition = 0;
		}
	}
}

bool testMakeDecimal(int* bin, int testNum)
{
	return testNum == makeDecimal(bin);
}

bool testBinarySum(int* binaryNum1, int* binaryNum2, int* testArray)
{
	int* resArray = new int[size]();
	binarySum(binaryNum1, binaryNum2, resArray);
	for (int i = 0; i < size; i++)
	{
		if (resArray[i] != testArray[i])
		{
			delete[] resArray;
			return false;
		}

	}
	delete[] resArray;
	return true;
}

bool testMakeBinary(int binaryNum, int* testArray)
{
	int* resArray = new int[size]();
	makeBinary(binaryNum, resArray);
	for (int i = 0; i < size; i++)
	{
		if (resArray[i] != testArray[i])
		{
			delete[] resArray;
			return false;
		}

	}
	delete[] resArray;
	return true;
}

/*bool test()
{
	int num = 4;
	int testBinaryNumFirst[size] = { 0,1,0,1};
	int testBinaryNumSecond[size] = { 0,1,0,1 };
	int testBinarySumValue[size] = { 1,0,1,0 };
	if (!testMakeBinary(num, testBinaryNumFirst))
	{
		return false;
	}
	if (!testBinarySum(testBinaryNumFirst, testBinaryNumSecond, testBinarySumValue))
	{
		return false;
	}
	if (!testMakeDecimal(testBinaryNumFirst, num))
	{
		return false;
	}
	return true;
}*/

int main(int argc, char* argv[])
{
	setlocale(0, "RUS");
	/*if (!test())
	{
		printf("Error");
		return 1;
	}*/
	int* binaryNum1 = new int[size]();
	enterNumber(binaryNum1);
	int* binaryNum2 = new int[size]();
	enterNumber(binaryNum2);
	int* binSum = new int[size]();
	binarySum(binaryNum1, binaryNum2, binSum);
	printf("Сумма:\n");
	showBinaryNumber(binSum);
	printf("В десятичной системе: %d", makeDecimal(binSum));
	delete[] binaryNum1; 
	delete[] binaryNum2;
	delete[] binSum;
	return 0;
}