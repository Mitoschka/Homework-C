#include "RabinKarp.h"
#include <string.h>

const int simpleNumb = 67;

int hashFunctionForString(char myString[])
{
	int power = 1;
	int result = 0;
	for (int i = strlen(myString) - 1; i != -1; --i)
	{
		result += static_cast<int>(myString[i]) * power;
		power *= simpleNumb;
	}

	return result;
}

int hashFunctionForChar(char someChar, int power)
{
	int tempPower = 1;
	for (int i = 1; i != power; ++i)
	{
		tempPower *= simpleNumb;
	}
	return static_cast<int>(someChar) * tempPower;
}

int findIndexOfSubstring(char someString[], char substring[])
{
	if (strlen(substring) > strlen(someString))
	{
		return -1;
	}
	int index = 0;
	int hashSubstring = hashFunctionForString(substring);
	char tempSubstring[100] = {};
	strncpy(tempSubstring, someString, strlen(substring));
	int hashTempSubstring = hashFunctionForString(tempSubstring);
	while (index < strlen(someString) - strlen(substring) + 1)
	{
		if (hashTempSubstring == hashSubstring)
		{
			if (strcmp(substring, tempSubstring) == 0)
			{
				return index;
			}
		}
		hashTempSubstring -= hashFunctionForChar(someString[index], strlen(tempSubstring));
		hashTempSubstring *= simpleNumb;
		hashTempSubstring += hashFunctionForChar(someString[index + strlen(substring)], 1);
		for (int i = 0; i != strlen(tempSubstring) - 1; ++i)
		{
			tempSubstring[i] = tempSubstring[i + 1];
		}

		tempSubstring[strlen(tempSubstring) - 1] = someString[index + strlen(substring)];
		++index;
	}

	return -1;
}