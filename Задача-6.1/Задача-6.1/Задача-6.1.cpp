#include <iostream>
#include <cstring>

#include "myStack.h"

const char plus = '+';
const char minus = '-';
const char multiplication = '*';
const char division = '/';

const int size = 100;

bool IsExpressionCounted(char expression[], int numberOfChars, int& resultOfExpression)
{
	MyStack* stack = createStack();

	int numberCounter = 0;
	int operationsCounter = 0;

	bool isInputCorrect = true;

	for (int i = 0; i != numberOfChars - 1; ++i)
	{
		if (expression[i] != ' ' && expression[i] != '=')
		{
			if (expression[i] >= '0' && expression[i] <= '9')
			{
				addElementInStack(stack, expression[i] - '0');
				++numberCounter;

			}
			else
			{
				if (isStackEmpty(stack))
				{
					isInputCorrect = false;
					break;
				}
				int secondNumber = deleteElementFromStack(stack);
				if (isStackEmpty(stack))
				{
					isInputCorrect = false;
					break;
				}
				int firstNumber = deleteElementFromStack(stack);

				++operationsCounter;
				int result = 0;

				switch (expression[i])
				{

				case plus:
				{
					result = firstNumber + secondNumber;
					addElementInStack(stack, result);

					break;
				}

				case minus:
				{
					result = firstNumber - secondNumber;
					addElementInStack(stack, result);

					break;
				}

				case multiplication:
				{
					result = firstNumber * secondNumber;
					addElementInStack(stack, result);

					break;
				}

				case division:
				{
					result = firstNumber / secondNumber;
					addElementInStack(stack, result);

					break;
				}

				default:
				{
					isInputCorrect = false;
					break;
				}
				}
			}
		}
	}


	if (operationsCounter + 1 == numberCounter && isInputCorrect && !isStackEmpty(stack))
	{
		resultOfExpression = deleteElementFromStack(stack);
	}
	else
	{
		isInputCorrect = false;
	}

	deleteStack(stack);

	return isInputCorrect;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char testExpression1[] = { '1','1','+','=' };
	int testSize = 4;
	int actualResult = 0;
	int expectedResult = 2;
	if (!IsExpressionCounted(testExpression1, testSize, actualResult) || actualResult != expectedResult)
	{
		printf("Тест 1 не пройден.");
		return 0;
	}

	char testExpression2[] = { '1', '+', '1', '=' };

	if (IsExpressionCounted(testExpression2, testSize, actualResult))
	{
		printf("Тест 2 не пройден.");
		return 0;
	}

	char currentSymbol = ' ';

	char expression[size];
	int i = 0;
	int numberOfChars = 0;

	bool isInputCorrect = true;

	printf("Введите выражение и знак равно ('='): ");
	while (currentSymbol != '=')
	{
		scanf("%c", &currentSymbol);
		expression[i] = currentSymbol;
		++i;
		++numberOfChars;
	}

	int result = 0;

	if (IsExpressionCounted(expression, numberOfChars, result))
	{
		printf("Значение введенного выражения: %d", result);
	}
	else
	{
		printf("Некорректный ввод.");
	}

	return 0;

}