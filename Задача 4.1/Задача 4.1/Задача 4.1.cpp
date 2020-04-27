#include <stdio.h>
#include <locale.h>

// максимальный размер массива для хранения двоичного представления числа
const int numberOfDigits = sizeof(int) * 8;

// структура двоичных чисел
struct BinaryNumber 
{
	// представление двоичного числа в виде массива
	bool arrayNumber[numberOfDigits]{};
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

// вывод двоичного числа на экран
void printBinaryNumber(BinaryNumber* binNumber)
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
		// складываем побитово оба числа и учитываем перенос
		int tempResultDigit = number->arrayNumber[i] + binOne->arrayNumber[i] + tempDigit;
		number->arrayNumber[i] = tempResultDigit % 2;
		tempDigit = tempResultDigit / 2;
	}
}

// сложение двух двоичных чисел, результат записывается в 
void sumOfTwoBinaryNumbers(BinaryNumber* firstNumber, BinaryNumber* secondNumber)
{
	// первое число
	int tempDigit = 0;
	for (int i = numberOfDigits - 1; i >= 0; --i)
	{
		int temp = firstNumber->arrayNumber[i] + secondNumber->arrayNumber[i] + tempDigit;
		firstNumber->arrayNumber[i] = temp % 2;
		tempDigit = temp / 2;
	}
}

// перевод десятичного числа в двоичное
void decToBin(int decNumber, BinaryNumber* binNumber)
{
	int helpBit = 0x80000000;
	for (int i = 0; i != numberOfDigits; ++i)
	{
		binNumber->arrayNumber[i] = (decNumber & helpBit);
		helpBit = helpBit >> 1;
		helpBit = helpBit & 0x7FFFFFFF;
	}
}

// перевод двоичного числа в десятичное
int binToDec(BinaryNumber* number)
{
	int resultInDec = 0;
	for (int i = numberOfDigits - 1; i >= 0; --i)
	{
		if (number->arrayNumber[i])
		{
			resultInDec += powerOfTwo(numberOfDigits - i - 1);
		}
	}

	return resultInDec;
}

bool test()
{
	bool isPassed = true;

	int testDec1 = -43;
	int testDec2 = 78;
	BinaryNumber* testBin1 = new BinaryNumber;
	BinaryNumber* testBin2 = new BinaryNumber;
	decToBin(testDec1, testBin1);
	decToBin(testDec2, testBin2);
	sumOfTwoBinaryNumbers(testBin1, testBin2);
	if (binToDec(testBin1) != 35)
	{
		isPassed = false;
	}

	delete testBin1;
	delete testBin2;

	int testDec3 = 272;
	int testDec4 = -599;
	BinaryNumber* testBin3 = new BinaryNumber;
	BinaryNumber* testBin4 = new BinaryNumber;
	decToBin(testDec3, testBin3);
	decToBin(testDec4, testBin4);
	sumOfTwoBinaryNumbers(testBin3, testBin4);
	if (binToDec(testBin3) != -327)
	{
		isPassed = false;
	}

	delete testBin3;
	delete testBin4;

	return isPassed;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		printf("Некоторые тесты не пройдены.");
		return 1;
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
		scanf("%d\n%d", &firstDecNumber, &secondDecNumber);
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

	delete firstBinaryNumber;
	delete secondBinaryNumber;

	return 0;
}