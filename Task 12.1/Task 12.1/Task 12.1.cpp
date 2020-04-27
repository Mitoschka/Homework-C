#include <iostream>

#include "RabinKarp.h"

const int maxSize = 100;

bool isCorrect()
{
	char testString[maxSize] = "dogcatbird";
	char testSbstr[maxSize] = "tbi";
	if (findIndexOfSubstring(testString, testSbstr) != 5)
	{
		return false;
	}

	char testLengthString[maxSize] = "aaa";
	char testLengthSbstr[maxSize] = "aaaa";
	if (findIndexOfSubstring(testLengthString, testLengthSbstr) != -1)
	{
		return false;
	}

	char testStringW[maxSize] = "helloworld";
	char testSbstrW[maxSize] = "wori";
	if (findIndexOfSubstring(testStringW, testSbstrW) != -1)
	{
		return false;
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isCorrect())
	{
		printf("test fail");
		return 1;
	}

	char substring[maxSize] = "";

	FILE* file = fopen("string.txt", "r");
	char stringFromFile[maxSize] = "";
	fscanf(file, "%s", stringFromFile);
	fclose(file);

	printf("Строка из файла: %s \n Какую подстроку найти? \n", stringFromFile);
	scanf("%s", substring);

	int index = findIndexOfSubstring(stringFromFile, substring);

	if (index == -1)
	{
		printf("Данной подстроки не существует.");
	}
	else
	{
		printf("Индекс первого вхождения: %d", index);
	}

	return 0;
}