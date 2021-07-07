#include "stateMachine.h"
#include <ctype.h>

enum calculatorStates { firstLetterState, restOfStringState };

bool isCorrectString(char* inputString)
{
	calculatorStates currentState = firstLetterState;
	int i = -1;

	while (true)
	{
		i++;
		char symbol = inputString[i];

		switch (currentState)
		{
		case firstLetterState:
		{
			if (isalpha(symbol))
			{
				currentState = restOfStringState;
				break;
			}

			return false;
		}
		case restOfStringState:
		{
			if (isalpha(symbol) || symbol == '_' || isdigit(symbol))
			{
				break;
			}

			if (symbol == '\0')
			{
				return true;
			}

			return false;
		}
		default:
			break;
		}
	}

	return false;
}