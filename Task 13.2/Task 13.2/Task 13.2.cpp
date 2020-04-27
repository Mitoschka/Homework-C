#include <stdio.h>
#include <iostream>
#include "stateMachine.h"

const int maxSize = 1000;

bool isCorrect()
{
	FILE* file = fopen("test.txt", "r");
	const char* expected = "/*dsRead(phoneBook))\n{\nprint*/\n/*umber = op/tio**/\n/*\n}*/\n";
	char* actual = analizeFile(file);
	if (strcmp(expected, actual) != 0)
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

	FILE* file = fopen("text.txt", "r");

	char* comments = analizeFile(file);

	printf("Комментарии в файле: \n %s", comments);

	fclose(file);

	return 0;
}