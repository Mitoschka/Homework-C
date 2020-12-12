#include "MyList.h"
#include <cstdio>
#include <stdlib.h>

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

// Создать список
List* createList()
{
	return new List;
}

// Проверить, является ли список пустым
bool isListEmpty(List* list)
{
	return list->head == nullptr;
}

//Проверить создан ли список
bool isListExist(List* list)
{
	return list != nullptr;
}

// Заполнить список случайными значениями
bool fillList(List* list, int sizeOfList, int start, int end)
{
	if (sizeOfList < 1 || start > end)
	{
		printf("Некорректные параметры.\n");
		return false;
	}
	int range = end - start + 1;
	for (int i = 0; i != sizeOfList; ++i)
	{
		int newValue = (rand() % range) + start;
		addElement(list, newValue);
	}

	return true;
}

// Развернуть список
List* reverseList(List* list)
{
	List* newList = createList();
	while (list->head != nullptr)
	{
		int tempValue = removeElement(list);
		addElement(newList, tempValue);
	}

	deleteList(list);

	return newList;
}

// Добавить элемент в начало списка
void addElement(List* list, int value)
{
	ListElement* listElement = new ListElement;
	listElement->value = value;
	listElement->next = list->head;
	list->head = listElement;
}

// Удалить элемент из начала списка и вернуть значение
int removeElement(List* list)
{
	ListElement* temp = list->head;
	int result = temp->value;
	list->head = list->head->next;
	delete temp;

	return result;
}

// Распечатать список
void showList(List* list)
{
	if (isListEmpty(list))
	{
		printf("Список пуст.\n");
		return;
	}
	printf("Список: ");
	ListElement* listElement = list->head;
	while (listElement != nullptr)
	{
		printf("%d ", listElement->value);
		listElement = listElement->next;
	}
	printf("\n");
}

// Удалить элемент из начала списка
void deleteElement(List* list)
{
	ListElement* temp = list->head;
	list->head = list->head->next;
	delete temp;
}

// Удалить список
void deleteList(List* list)
{
	if (list == nullptr)
	{
		return;
	}
	while (list->head != nullptr)
	{
		deleteElement(list);
	}

	delete list;
}