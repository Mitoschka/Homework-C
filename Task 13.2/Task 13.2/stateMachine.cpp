#include "stateMachine.h"
#include <stdio.h>
#include <string.h>

const int maxSize = 1000;

int move(char symbol)
{
	if (symbol == '/')
	{
		return 1;
	}
	else if (symbol == '*')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}


char* analizeFile(FILE* file)
{
	int numberOfStates = 0;
	fscanf(file, "%d", &numberOfStates);
	int numberOfToken = 0;
	fscanf(file, "%d", &numberOfToken);

	int** tableOfStates = new int* [numberOfStates];

	for (int i = 0; i != numberOfStates; ++i)
	{
		tableOfStates[i] = new int[numberOfToken];
	}

	for (int i = 0; i != numberOfStates; ++i)
	{
		for (int j = 0; j != numberOfToken; ++j)
		{
			fscanf(file, "%d", &tableOfStates[i][j]);
		}
	}

	int currentState = 0;
	int previousState = 0;
	char comments[maxSize] = {};
	char symbol = fgetc(file);
	while (symbol != EOF) {
		previousState = currentState;
		currentState = tableOfStates[currentState][move(symbol)];
		if (previousState == 1 && currentState == 2)
		{
			strcat(comments, "/");
		}
		if (currentState == 2 || currentState == 3)
		{
			char symbolInArray[1] = { symbol };
			strncat(comments, symbolInArray, 1);
		}
		if (previousState == 3 && currentState == 0)
		{
			strcat(comments, "/\n");
		}
		symbol = fgetc(file);
	}

	for (int i = 0; i != numberOfStates; ++i)
	{
		delete tableOfStates[i];
	}

	delete tableOfStates;

	return comments;
}