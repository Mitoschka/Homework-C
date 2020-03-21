#include <iostream>
#include <stdio.h>
#include <string.h>

#include "MyStack.h"

const int size = 30;

bool isExpressionCorrect(char infixExpression[], char postfixExpression[])
{
	const char plus = '+';
	const char minus = '-';
	const char multiplication = '*';
	const char division = '/';
	char currentSymbol = ' ';

	MyStack* resultStack = createStack();
	MyStack* stackForOperations = createStack();

	int numbersCounter = 0;
	int operationCounter = 0;
	int bracketsCounter = 0;

	int i = 0;
	currentSymbol = infixExpression[i];

	while (currentSymbol != '=')
	{
		if (currentSymbol != '=' && currentSymbol != ' ')
		{
			if (currentSymbol >= '0' && currentSymbol <= '9')
			{
				++numbersCounter;
				pushToStack(resultStack, currentSymbol);
			}
			else if (currentSymbol == plus || currentSymbol == minus)
			{
				++operationCounter;
				while (!isStackEmpty(stackForOperations) && (headOfStack(stackForOperations) == multiplication || headOfStack(stackForOperations) == division))
				{
					if (isStackEmpty(stackForOperations))
					{
						deleteStack(stackForOperations);
						deleteStack(resultStack);
						return false;
					}
					pushToStack(resultStack, popFromStack(stackForOperations));
				}

				pushToStack(stackForOperations, currentSymbol);
			}
			else if (currentSymbol == multiplication || currentSymbol == division)
			{
				++operationCounter;
				pushToStack(stackForOperations, currentSymbol);
			}
			else if (currentSymbol == '(')
			{
				++bracketsCounter;
				pushToStack(stackForOperations, currentSymbol);
			}
			else if (currentSymbol == ')')
			{
				--bracketsCounter;
				while (headOfStack(stackForOperations) != '(')
				{
					pushToStack(resultStack, popFromStack(stackForOperations));
					if (isStackEmpty(stackForOperations))
					{
						deleteStack(stackForOperations);
						deleteStack(resultStack);
						return false;
					}
				}
				if (isStackEmpty(stackForOperations))
				{
					deleteStack(stackForOperations);
					deleteStack(resultStack);
					return false;
				}
				char anotherOpenBracket = popFromStack(stackForOperations);
			}
			else
			{
				deleteStack(stackForOperations);
				deleteStack(resultStack);
				return false;
			}
		}

		++i;
		currentSymbol = infixExpression[i];
	}

	if ((numbersCounter != operationCounter + 1) || bracketsCounter)
	{
		deleteStack(stackForOperations);
		deleteStack(resultStack);
		return false;
	}

	while (!isStackEmpty(stackForOperations))
	{
		pushToStack(resultStack, popFromStack(stackForOperations));
	}

	deleteStack(stackForOperations);

	resultStack = reverseStack(resultStack);

	int k = 0;
	while (!isStackEmpty(resultStack))
	{
		postfixExpression[k] = popFromStack(resultStack);
		++k;
	}

	deleteStack(resultStack);

	return true;
}

void showExpression(char expression[])
{
	for (int i = 0; i != strlen(expression); ++i)
	{
		printf("%c ", expression[i]);
	}
}

bool isCorrect()
{
	bool isCorrect = true;
	char testExpression1[] = "1+(2+3)*4+5*6-9=";
	char actualExpression1[size]{};
	char expectedExpression1[] = "123+4*56*9-++";
	if (!isExpressionCorrect(testExpression1, actualExpression1))
	{
		printf("Тест 1 не пройден.\n");
		isCorrect = false;
	}

	if (strcmp(actualExpression1, expectedExpression1) != 0)
	{
		printf("Тест 2 не пройден.\n");
		isCorrect = false;
	}

	char testExpression2[] = "1 + (2*2)* =";

	if (isExpressionCorrect(testExpression2, actualExpression1))
	{
		printf("Тест 3 не пройден.\n");
		isCorrect = false;
	}

	return isCorrect;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isCorrect())
	{
		printf("Какие-то тесты не пройдены.");
		return 0;
	}

	char infixExpression[size]{};
	char postfixExpression[size]{};

	printf("Введите выражение в инфиксной форме и завершающий знак 'равно' (=): ");
	fgets(infixExpression, size, stdin);

	if (isExpressionCorrect(infixExpression, postfixExpression))
	{
		printf("Выражение в постфиксной форме: \n");
		showExpression(postfixExpression);
	}
	else
	{
		printf("Некорректный ввод.");
	}

	return 0;
}