#include "MyList.h"

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
	ListElement* beforeHead = nullptr;
};

List* createList()
{
	return new List;
}

ListElement* createListElement()
{
	return new ListElement;
}

ListElement* beforeHeadElement(List* list)
{
	return list->beforeHead;
}

ListElement* nextListElement(ListElement* listElement)
{
	return listElement->next;
}

int valueOfListElement(ListElement* listElement)
{
	return listElement->value;
}

void initList(List* list, int numberOfElements)
{
	for (int i = numberOfElements; i != 0; --i) //делаем циклический список, каждое значение списка - порядковый номер воина
	{
		ListElement* listElement = new ListElement;
		listElement->value = i;
		listElement->next = list->head;
		list->head = listElement;
	}

	ListElement* listElement = list->head;

	while (listElement->next != nullptr)
	{
		listElement = listElement->next;
	}
	listElement->next = list->head;

	list->beforeHead = listElement;
}

void changeNextToNextNext(ListElement* listElement)
{
	listElement->next = listElement->next->next;
}

ListElement* getHead(List* list)
{
	return list->head;
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		ListElement* temp = list->head->next;
		delete list->head;
		list->head = temp;
	}

	delete list;
}