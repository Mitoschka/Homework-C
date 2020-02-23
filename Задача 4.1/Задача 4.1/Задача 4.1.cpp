#include <iostream>

const int numberOfDigits = 10; // максимальный размер массива для хранения двоичного представления числа

struct BinaryNumber // класс двоичных чисел
{
	BinaryNumber()
	{
		for (int i = 0; i != numberOfDigits; ++i)
		{
			arrayNumber[i] = false;
		}
	}
	bool arrayNumber[numberOfDigits]; // представление двоичного числа в виде массива
};

int powerOfTwo(int degree)
{
	int result = 1;
	for (int i = 0; i != degree; ++i)
	{
		result *= 2;
	}
	return result;
}

void reverseDigits(BinaryNumber* binNumber)
{
	for (int i = 0; i != numberOfDigits - 1; ++i)
	{
		binNumber->arrayNumber[i] = !binNumber->arrayNumber[i];
	}
}

void printBinaryNumber(BinaryNumber* binNumber) // вывод двоичного числа на экран
{
	for (int i = numberOfDigits - 1; i != -1; --i)
	{
		printf("%d", binNumber->arrayNumber[i]);
	}
}

void plusBinaryOne(BinaryNumber* number)
{
	BinaryNumber* binOne = new BinaryNumber;
	binOne->arrayNumber[0] = true;
	bool tempDigit = false;
	for (int i = 0; i != numberOfDigits - 1; ++i)
	{
		int tempResultDigit = number->arrayNumber[i] + binOne->arrayNumber[i] + tempDigit; // складываем побитово оба числа и учитываем перенос
		number->arrayNumber[i] = tempResultDigit % 2;
		tempDigit = tempResultDigit / 2;
	}
}

void sumOfTwoBinaryNumbers(BinaryNumber* firstNumber, BinaryNumber* secondNumber) // сложение двух двоичных чисел, результат записывается в 
{																			// первое(!!!) число
	bool tempDigit = false; // переменная, отвечающая за битовый перенос
	for (int i = 0; i != numberOfDigits; ++i)
	{
		int tempResultDigit = firstNumber->arrayNumber[i] + secondNumber->arrayNumber[i] + tempDigit; // складываем побитово оба числа и учитываем перенос
		firstNumber->arrayNumber[i] = tempResultDigit % 2;
		tempDigit = tempResultDigit / 2;
	}
}

void decToBin(int decNumber, BinaryNumber* binNumber) // перевод десятичного числа в двоичное
{
	bool isPositive = (decNumber >= 0);
	if (!isPositive)
	{
		decNumber = decNumber * (-1);
	}

	int i = 0;

	while (decNumber != 0) // пока число не равно нулю
	{
		binNumber->arrayNumber[i] = decNumber % 2; // записываем остаток деления на два
		++i;                                 // переходим на следующий разряд
		decNumber /= 2;
	}

	if (!isPositive)
	{
		reverseDigits(binNumber);
		binNumber->arrayNumber[numberOfDigits - 1] = true; //обозначили, что это отрицательное число
		plusBinaryOne(binNumber);
	}
}

int binToDec(BinaryNumber* number) // перевод двоичного числа в десятичное
{
	int resultInDec = 0;
	bool isPositive = !number->arrayNumber[numberOfDigits - 1];
	if (!isPositive)
	{
		reverseDigits(number);
		plusBinaryOne(number);
	}
	for (int i = 0; i != numberOfDigits - 1; ++i)
	{
		resultInDec += number->arrayNumber[i] * powerOfTwo(i);
	}
	if (!isPositive)
	{
		resultInDec *= -1;
	}
	return resultInDec;
}

bool test()
{
	bool isPassed = true;
	int testDecNumber = -117;
	bool correctBinary[] = { true, true, false, true, false, false, false, true, true, true };
	BinaryNumber* testBinaryNumber = new BinaryNumber;
	decToBin(testDecNumber, testBinaryNumber);
	for (int i = 0; i != numberOfDigits; ++i)
	{
		if (correctBinary[i] != testBinaryNumber->arrayNumber[i])
		{
			isPassed = false;
			printf("decToBin test failed\n");
			break;
		}
	}

	bool testBinary[] = { false, false, true, true, true, false, true, false, false, false };
	int correctDecNumber = 92;
	for (int i = 0; i != numberOfDigits; ++i)
	{
		testBinaryNumber->arrayNumber[i] = testBinary[i];
	}
	if (correctDecNumber != binToDec(testBinaryNumber))
	{
		isPassed = false;
		printf("binToDec test failed\n");
	}

	bool testCorrectPlusOne[] = { true, false, true, true, true, false, true, false, false, false };
	plusBinaryOne(testBinaryNumber);
	for (int i = 0; i != numberOfDigits; ++i)
	{
		if (testCorrectPlusOne[i] != testBinaryNumber->arrayNumber[i])
		{
			isPassed = false;
			printf("plusBinaryOne test failed\n");
			break;
		}
	}

	int testDec1 = -43;
	int testDec2 = 78;
	BinaryNumber* testBin1 = new BinaryNumber;
	BinaryNumber* testBin2 = new BinaryNumber;
	decToBin(testDec1, testBin1);
	decToBin(testDec2, testBin2);
	sumOfTwoBinaryNumbers(testBin1, testBin2);
	bool correctSum[] = { true, true, false, false, false, true, false, false, false, false };
	for (int i = 0; i != numberOfDigits; ++i)
	{
		if (correctSum[i] != testBin1->arrayNumber[i])
		{
			isPassed = false;
			printf("sumOfTwo test failed\n");
			break;
		}
	}

	return isPassed;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		printf("Некоторые тесты не пройдены.");
		return 0;
	}

	int maximum = (powerOfTwo(numberOfDigits - 1) - 1) / 2 - 1;
	int minimum = -powerOfTwo(numberOfDigits - 1) / 2 + 1;

	int firstDecNumber = 0;
	int secondDecNumber = 0;

	printf("Введите два числа в промежутке от %d до %d: ", minimum, maximum);
	scanf("%d\n%d", &firstDecNumber, &secondDecNumber);

	while (firstDecNumber < minimum || firstDecNumber > maximum || secondDecNumber < minimum || secondDecNumber > maximum)
	{
		printf("Числа должны быть в промежутке от %d до %d. Попробуйте еще раз: ", minimum, maximum);
		scanf("%d, %d", &firstDecNumber, &secondDecNumber);
	}

	BinaryNumber* firstBinaryNumber = new BinaryNumber;
	BinaryNumber* secondBinaryNumber = new BinaryNumber;

	decToBin(firstDecNumber, firstBinaryNumber);
	decToBin(secondDecNumber, secondBinaryNumber);

	printf("Число %d в двоичном представлении (дополнительный код): ", firstDecNumber);
	printBinaryNumber(firstBinaryNumber);
	printf("\n");

	printf("Число %d в двоичном представлении (дополнительный код): ", secondDecNumber);
	printBinaryNumber(secondBinaryNumber);
	printf("\n");

	printf("Сумма чисел в двоичном представлении (дополнительный код): ");
	sumOfTwoBinaryNumbers(firstBinaryNumber, secondBinaryNumber);
	printBinaryNumber(firstBinaryNumber);
	printf("\n");

	printf("Сумма чисел в десятичном представлении: %d", binToDec(firstBinaryNumber));

	return 0;
}