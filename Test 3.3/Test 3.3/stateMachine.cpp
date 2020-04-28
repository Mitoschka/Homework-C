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
			if ((symbol <= 'Z' && symbol >= 'A') || (symbol <= 'z' && symbol >= 'a'))
			{
				currentState = restOfStringState;
				break;
			}

			return false;
		}
		case restOfStringState:
		{
			if ((symbol <= 'Z' && symbol >= 'A') || (symbol <= 'z' && symbol >= 'z') || symbol == '_' || isdigit(symbol))
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