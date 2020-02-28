#include <stdio.h>
#include  <iostream>
#include "MyStack.h"

bool test()
{
	bool isCorrect = true;
	MyStack* testStack = createStack();
	int testValue1 = 1;
	int testValue2 = 2;
	int testValue3 = 3;
	addElementInStack(testStack, testValue1);
	addElementInStack(testStack, testValue2);

	if (deleteElementFromStack(testStack) != testValue2 || deleteElementFromStack(testStack) != testValue1)
	{
		printf("Тест 1 не пройдент\n");
		isCorrect = false;
	}

	if (!isEmpty(testStack))
	{
		printf("Тест 2 не пройден\n");
		isCorrect = false;
	}

	addElementInStack(testStack, testValue1);

	if (isEmpty(testStack))
	{
		printf("Тест 3 не пройден\n");
		isCorrect = false;
	}

	addElementInStack(testStack, testValue3);
	duplicateHead(testStack);

	if (deleteElementFromStack(testStack) != testValue3 || deleteElementFromStack(testStack) != testValue3 || deleteElementFromStack(testStack) != testValue1)
	{
		printf("Тест 4 не пройден\n");
		isCorrect = false;
	}

	deleteStack(testStack);

	return isCorrect;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		printf("Тесты не пройдены");
		return 0;
	}

	MyStack* myStack = createStack();
	int operation = -1;

	while (operation)
	{
		printf("Введите номер операции:\n");
		printf("0 - выйти\n");
		printf("1 - добавить число на вершину стека\n");
		printf("2 - удалить число с вершины стека\n");
		printf("3 - дублировать число на вершине стека\n");
		printf("4 - распечатать стек\n");
		scanf("%d", &operation);

		switch (operation)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			printf("Какое число положить в стек?\n");
			int value = 0;
			scanf("%d", &value);
			addElementInStack(myStack, value);
			break;
		}
		case 2:
		{
			if (isEmpty(myStack))
			{
				printf("Стек сейчас пуст, удаление элемента невозможно.\n");
			}
			else
			{
				deleteElementFromStack(myStack);
			}
			break;
		}
		case 3:
		{
			if (isEmpty(myStack))
			{
				printf("Стек сейчас пуст.\n");
			}
			else
			{
				duplicateHead(myStack);
			}
			break;
		}
		case 4:
		{
			printStack(myStack);
			break;
		}
		default:
		{
			printf("Некорректная операция.\n");
			break;
		}
		}
	}

	deleteStack(myStack);

	return 0;
}