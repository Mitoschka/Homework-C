#define _CRT_SECURE_NO_WARNINGS
#include "myList.h"

const int size = 100;

struct ListElement
{
	char value[size];
	ListElement * next = nullptr;
};

struct List
{
	size_t numberOfElements = 0;
	ListElement * head = nullptr;
};

List * createList()
{
	List * list = new List;
	return list;
}

List ** createArrayOfList(int capacity)
{
	List ** result = new List*[capacity];
	return result;
}

size_t numberOfElements(List * list)
{
	return list->numberOfElements;
}

bool isContain(List * list, char value[])
{
	ListElement * currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (strcmp(value, currentElement->value) == 0)
		{
			return true;
		}
		currentElement = currentElement->next;
	}

	return false;
}

int numberOfDifferentElements(List * list)
{
	if (list->head == nullptr)
	{
		return 0;
	}
	int result = 0;
	List * tempList = new List;
	ListElement * currentElement = list->head;
	while (currentElement != nullptr)
	{
		if (!isContain(tempList, currentElement->value))
		{
			++result;
			addElementToList(tempList, currentElement->value);
		}

		currentElement = currentElement->next;
	}

	deleteList(tempList);

	return result;
}

ListElement * getHead(List * list)
{
	return list->head;
}

void addElementToList(List * list, char value[])
{
	ListElement * listElement = new ListElement;
	strcpy(listElement->value, value);
	listElement->next = list->head;
	list->head = listElement;
	++list->numberOfElements;
}

void deleteElementFromList(List * list)
{
	ListElement *temp = list->head;
	list->head = list->head->next;
	--list->numberOfElements;
	delete temp;
}

void printList(List * list)
{
	ListElement * currentElement = list->head;
	while (currentElement != nullptr)
	{
		printf("%s", currentElement->value);
		currentElement = currentElement->next;
	}
}

void printHead(List * list)
{
	printf("%s", list->head->value);
}

void deleteList(List * list)
{
	while (list->head != nullptr)
	{
		deleteElementFromList(list);
	}

	delete list;
}