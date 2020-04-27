#include <stdio.h>
#include <iostream>

#include "myStack.h"

bool isBracketsCorrect(char brackets[])
{
	MyStack* stack = createStack();
	int i = 0;

	while (brackets[i] != '\0')
	{
		switch (brackets[i])
		{
		case '(':
		case '[':
		case '{':
		{
			addElementInStack(stack, brackets[i]);
			++i;
			break;
		}

		case ')':
		case ']':
		case '}':
		{
			if (isStackEmpty(stack))
			{
				deleteStack(stack);
				return false;
			}
			char nextBracket = deleteElementFromStack(stack);
			if (abs(brackets[i] - nextBracket) > 2)
			{
				deleteStack(stack);
				return false;
			}
			++i;
			break;
		}

		default:
		{
			++i;
			break;
		}
		}
	}

	if (isStackEmpty(stack))
	{
		deleteStack(stack);
		return true;
	}

	deleteStack(stack);
	return false;
}

bool test()
{
	bool isCorrect = true;
	MyStack* testStack = createStack();

	if (!isStackEmpty(testStack))
	{
		isCorrect = false;
		printf("Тест 1 не пройден.\n");
	}
	int testValue1 = 1;
	int testValue2 = 2;
	addElementInStack(testStack, testValue1);

	if (isStackEmpty(testStack))
	{
		isCorrect = false;
		printf("Тест 2 не пройден.\n");
	}

	addElementInStack(testStack, testValue2);

	if (deleteElementFromStack(testStack) != testValue2)
	{
		isCorrect = false;
		printf("Тест 3 не пройден.\n");
	}

	deleteStack(testStack);

	char testBrackets1[] = { '{', '(', ')', '}' };
	if (!isBracketsCorrect(testBrackets1))
	{
		isCorrect = false;
		printf("Тест 4 не пройден.\n");
	}

	char testBrackets2[] = { '{', '[', ']', ')' };
	if (isBracketsCorrect(testBrackets2))
	{
		isCorrect = false;
		printf("Тест 5 не пройден.\n");
	}

	char testBrackets3[] = { '(' };
	if (isBracketsCorrect(testBrackets3))
	{
		isCorrect = false;
		printf("Тест 6 не пройден.\n");
	}

	return isCorrect;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		printf("Некоторые тесты не пройдены.\n");
		return 0;
	}

	char brackets[100];

	printf("Введите последовательность скобок (последовательность кончается пробелом): ");
	scanf("%s", brackets);

	if (isBracketsCorrect(brackets))
	{
		printf("Баланс скобок соблюден.");
	}
	else
	{
		printf("Баланск скобок не соблюден.");
	}

	return 0;
}