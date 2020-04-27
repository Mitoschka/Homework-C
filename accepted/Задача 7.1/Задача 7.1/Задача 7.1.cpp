#include <iostream>
#include "MyList.h"

const int size = 5;

int main()
{
	setlocale(LC_ALL, "Russian");

	List* testList = createList();

	if (!isListEmpty(testList))
	{
		printf("Ошибка в проверке на пустоту списка.");
		deleteList(testList);
		return 0;
	}

	addElement(testList, 1);

	if (!isValueExistInList(testList, 1))
	{
		printf("Ошибка в добавлении элемента.");
		deleteList(testList);
		return 0;
	}

	if (isValueExistInList(testList, 0))
	{
		printf("Ошибка в проверке на существование.");
		deleteList(testList);
		return 0;
	}

	deleteElement(testList, 1);

	if (isValueExistInList(testList, 1))
	{
		printf("Ошибка в удалении элемента.");
		deleteList(testList);
		return 0;
	}

	addElement(testList, 2);
	addElement(testList, 0);
	addElement(testList, 4);
	addElement(testList, 1);
	addElement(testList, 3);
	int testArray[size];
	int testCorrectArray[size] = { 0, 1, 2, 3, 4 };
	putElementsInArray(testList, testArray);
	for (int i = 0; i != size; ++i)
	{
		if (testArray[i] != testCorrectArray[i])
		{
			printf("Ошибка в сортированности листа.");
			deleteList(testList);
			return 0;
		}
	}

	deleteList(testList);

	List* list = createList();
	int operation = -1;

	while (operation)
	{
		printf("Введите номер операции:\n");
		printf("0 - выйти\n");
		printf("1 - добавить значение в список\n");
		printf("2 - удалить значение из списка\n");
		printf("3 - распечатать список\n");
		scanf_s("%d", &operation);

		switch (operation)
		{
		case 0:
			break;
		case 1:
		{
			int value = 0;
			printf("Введите значение добавляемого элемента: ");
			scanf_s("%d", &value);
			addElement(list, value);
			break;
		}
		case 2:
		{
			int value = 0;
			printf("Введите значение, которое нужно удалить из списка: ");
			scanf_s("%d", &value);
			deleteElement(list, value);
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