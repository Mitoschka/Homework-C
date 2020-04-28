#include "stateMachine.h"

bool isCorrectString(char* inputString)
{
	int currentState = 0;
	int i = 0;

	while (true)
	{
		char symbol = inputString[i];

		switch (currentState)
		{
		case 0:
		{
			if (symbol <= 'Z' && symbol >= 'A')
			{
				currentState = 1;
				i++;
				break;
			}

			if (symbol <= 'z' && symbol >= 'a')
			{
				currentState = 1;
				i++;
				break;
			}

			return false;
		}
		case 1:
		{
			if (symbol <= 'Z' && symbol >= 'A')
			{
				i++;
				break;
			}

			if (symbol <= 'z' && symbol >= 'z')
			{
				i++;
				break;
			}

			if (symbol <= '9' && symbol >= '0')
			{
				i++;
				break;
			}

			if (symbol == '_')
			{
				i++;
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