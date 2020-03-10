#include "MyList.h"

void initList(List* list, int numberOfElements)
{
	for (int i = numberOfElements; i != 0; --i) //делаем циклический список, каждое значение списка - порядковый номер воина
	{
		ListElement* listElement = new ListElement;
		listElement->value = i;
		listElement->next = list->head;
		list->head = listElement;
	}
}

ListElement* getHead(List* list)
{
	return list->head;
}