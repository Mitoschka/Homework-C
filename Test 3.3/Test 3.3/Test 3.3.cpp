#include <stdio.h>
#include "stateMachine.h"

bool isCorrect()
{
	char string1[] = "aBz1_0";
	bool test1 = isCorrectString(string1);

	char string2[] = "";
	bool test2 = !isCorrectString(string2);

	char string3[] = "1_0";
	bool test3 = !isCorrectString(string3);

	char string4[] = "1Bz";
	bool test4 = !isCorrectString(string4);

	char string5[] = "a";
	bool test5 = isCorrectString(string5);

	char string6[] = "a_________!_________1000)";
	bool test6 = !isCorrectString(string6);

	return test1 && test2 && test3 && test4 && test5 && test6;
}

int main()
{
	if (!isCorrect())
	{
		printf("Tests failed!\n");
		return 1;
	}

	return 0;
}