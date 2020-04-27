#define _CRT_SECURE_NO_WARNINGS
#include "myList.h"
#include <string.h>
#include <stdio.h>

const int size = 100;

struct ListElement
{
public:
	char value[size];
	int counter = 0;
	ListElement* next = nullptr;
};

struct MyList
{
	int numberOfElements = 0;
	ListElement* head = nullptr;
};

MyList* createList()
{
	MyList* list = new MyList;
	return list;
}

MyList** createArrayOfList(int capacity)
{
	MyList** result = new MyList * [capacity];
	return result;
}

int numberOfElements(MyList* list)
{
	return list->numberOfElements;
}

bool isContain(MyList* list, char value[])
{
	ListElement* currentElement = list->head;
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

int numberOfDifferentElements(MyList* list)
{
	if (list->head == nullptr)
	{
		return 0;
	}
	int result = 0;
	MyList* tempList = new MyList;
	ListElement* currentElement = list->head;
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

ListElement* getHead(MyList* list)
{
	return list->head;
}

ListElement* getNext(ListElement* listElement)
{
	return listElement->next;
}

int getCounterElement(ListElement* listElement)
{
	return listElement->counter;
}

void getValue(ListElement* listElement, char value[])
{
	strcpy(value, listElement->value);
}

void addElementToList(MyList* list, char value[])
{
	ListElement* listElement = new ListElement;
	strcpy(listElement->value, value);
	listElement->next = list->head;
	list->head = listElement;
	++list->numberOfElements;
}

void addUniqueElementToList(MyList* list, char value[])
{
	if (list->head == nullptr)
	{
		list->head = new ListElement;
		strcpy(list->head->value, value);
		++list->head->counter;
		return;
	}

	ListElement* currentElement = list->head;
	while (currentElement->next != nullptr)
	{
		if (strcmp(currentElement->value, value) == 0)
		{
			++currentElement->counter;
			return;
		}
		currentElement = currentElement->next;
	}

	if (strcmp(currentElement->value, value) == 0)
	{
		++currentElement->counter;
	}
	else
	{
		currentElement->next = new ListElement;
		strcpy(currentElement->next->value, value);
		++currentElement->next->counter;
	}
}

void deleteElementFromList(MyList* list)
{
	ListElement* temp = list->head;
	list->head = list->head->next;
	--list->numberOfElements;
	delete temp;
}

void printList(MyList* list)
{
	ListElement* currentElement = list->head;
	while (currentElement != nullptr)
	{
		printf("%s", currentElement->value);
		currentElement = currentElement->next;
	}
}

void printHead(MyList* list)
{
	printf("%s", list->head->value);
}

void deleteList(MyList* list)
{
	while (list->head != nullptr)
	{
		deleteElementFromList(list);
	}

	delete list;
}