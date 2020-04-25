#include "MyList.h"

struct ListElement
{
	int value = 0;
	ListElement* next = nullptr;
};

struct List
{
	int numberOfElements = 0;
	ListElement* head = nullptr;
};

List* createList()
{
	return new List;
}

List** createArrayOfList(int size)
{
	return new List * [size];
}

int numberOfElementsInList(List* list)
{
	return list->numberOfElements;
}

ListElement* getHead(List* list)
{
	return list->head;
}

ListElement* getNext(ListElement* listElement)
{
	return listElement->next;
}

int valueFromElement(ListElement* listElement)
{
	return listElement->value;
}

void addElementInList(List* list, int town)
{
	ListElement* listElement = new ListElement;
	listElement->value = town;
	listElement->next = list->head;
	list->head = listElement;
	++list->numberOfElements;
}

int removeElementFromList(List* list)
{
	int tempValue = list->head->value;
	ListElement* temp = list->head;
	list->head = list->head->next;
	--list->numberOfElements;
	delete temp;
	return tempValue;
}

bool isContain(List* list, int value)
{
	if (list->head == nullptr)
	{
		return false;
	}

	ListElement* cursor = list->head;
	while (cursor->next != nullptr && cursor->value != value)
	{
		cursor = cursor->next;
	}

	return cursor->value == value;

}

List* reverseList(List* list)
{
	List* tempList = new List;
	while (list->head != nullptr)
	{
		addElementInList(tempList, removeElementFromList(list));
	}
	delete list;
	return tempList;
}

void deleteList(List* list)
{
	if (list->head != nullptr)
	{
		removeElementFromList(list);
	}

	delete list;
}

void deleteArrayOfList(List** arrayOfList, int size)
{
	for (int i = 0; i != size; ++i)
	{
		deleteList(arrayOfList[i]);
	}

	delete[] arrayOfList;
}