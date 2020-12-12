#include <iostream>
#include "MyList.h"

bool test()
{
	List* testList = createList();
	if (!isListEmpty(testList))
	{
		printf("Не пройден тест 1.\n");
		deleteList(testList);
		return false;
	}

	int testSize = 5;
	int testStart = 0;
	int testEnd = 10;

	if (!fillList(testList, testSize, testStart, testEnd))
	{
		printf("Не пройдент тест 1.1.\n");
		deleteList(testList);
		return false;
	}

	if (isListEmpty(testList))
	{
		printf("Не пройдент тест 2.\n");
		deleteList(testList);
		return false;
	}

	deleteList(testList);

	if (!isListExist(testList))
	{
		printf("Не пройдент тест 3.\n");
		return false;
	}

	testSize = 5;
	testStart = -3;
	testEnd = 7;
	testList = createList();
	fillList(testList, testSize, testStart, testEnd);

	if (isListEmpty(testList))
	{
		printf("Не пройдент тест 4.\n");
		deleteList(testList);
		return false;
	}

	testSize = -5;

	if (fillList(testList, testSize, testStart, testEnd))
	{
		printf("Не пройдент тест 5.\n");
		deleteList(testList);
		return false;
	}

	testSize = 10;
	testStart = 100;

	if (fillList(testList, testSize, testStart, testEnd))
	{
		printf("Не пройдент тест 6.\n");
		deleteList(testList);
		return false;
	}

	deleteList(testList);

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		return -1;
	}

	List* list = createList();
	int operation = -1;

	while (operation)
	{
		printf("Введите номер операции:\n");
		printf("0 - выйти\n");
		printf("1 - заполнить список случайными значениями\n");
		printf("2 - развернуть список\n");
		printf("3 - распечатать список\n");
		scanf("%d", &operation);

		switch (operation)
		{
		case 0:
			break;
		case 1:
		{
			printf("Введите размер списка: ");
			int sizeOfList = 0;
			scanf("%d", &sizeOfList);
			int start = 0;
			printf("Введите начало диапазона значений: ");
			scanf("%d", &start);
			int end = 0;
			printf("Введите конец диапазона: ");
			scanf("%d", &end);
			if (!isListEmpty(list))
			{
				deleteList(list);
				list = createList();
			}
			fillList(list, sizeOfList, start, end);
			break;
		}
		case 2:
		{
			if (isListEmpty(list))
			{
				printf("Список сейчас пуст!\n");
			}
			else
			{
				list = reverseList(list);
				printf("Список успешно развернут.\n");
			}
			break;
		}
		case 3:
		{
			showList(list);
			break;
		}
		default:
		{
			printf("Некорректная операция.\n");
			break;
		}
		}
	}

	deleteList(list);

	return 0;
}