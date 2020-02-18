#include <iostream>

struct ListElement
{
	int value;
	int position;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
	int count = 0;
};

void addElement(List* list)
{
	int value = 0;
	int position = 0;
	printf("Введите значение добавляемого элемента: ");
	scanf("%d", &value);
	printf("Введите позицию, в которую хотите добавить элемент: ");
	scanf("%d", &position);

	if (position > list->count)
	{
		printf("В данную позицию нельзя добавить элемент.\n");
		return;
	}

	ListElement* listElement = new ListElement;
	listElement->value = value;
	listElement->position = position;
	listElement->next = list->head;
	list->head = listElement;
	while (listElement->next != nullptr && listElement->position > listElement->next->position)
	{
		int temp = listElement->value;
		listElement->value = listElement->next->value;
		listElement->next->value = temp;

		temp = listElement->position;
		listElement->position = listElement->next->position;
		listElement->next->position = temp;

		listElement = listElement->next;
	}
	++list->count;
}

void deleteElement(List* list)
{
	if (list->count == 0)
	{
		printf("Список пуст.\n");
		return;
	}
	int position = 0;
	printf("Введите позицию, из которой нужно удалить элемент: ");
	scanf("%d", &position);

	if (position >= list->count)
	{
		printf("Такой позиции нет в списке.\n");
		return;
	}

	if (position == 0)
	{
		ListElement* tempListElement = new ListElement;
		tempListElement = list->head;
		list->head = list->head->next;
		delete tempListElement;
	}
	else
	{
		ListElement* listElement = list->head;
		while (listElement->next->position != position)
		{
			if (listElement->next->position != position)
			{
				listElement = listElement->next;
			}
		}
		ListElement* tempListElement = new ListElement;
		tempListElement = listElement->next;
		listElement->next = tempListElement->next;
		delete tempListElement;
	}
	--list->count;
}

void changePositions(List* list)
{
	ListElement* listElement = new ListElement;
	listElement = list->head;
	int tempPosition = 0;
	while (listElement != nullptr)
	{
		listElement->position = tempPosition;
		listElement = listElement->next;
		++tempPosition;
	}
}

void showList(List* list)
{
	if (list->count == 0)
	{
		printf("Список пуст.\n");
		return;
	}
	printf("Список: ");
	ListElement* listElement = new ListElement;
	listElement = list->head;
	while (listElement != nullptr)
	{
		printf("%d ", listElement->value);
		listElement = listElement->next;
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");

	List* list = new List;
	int operation = -1;

	while (operation)
	{
		printf("Введите номер операции:\n");
		printf("0 - выйти\n");
		printf("1 - добавить значение в список\n");
		printf("2 - удалить значение из списка\n");
		printf("3 - распечатать список\n");
		scanf("%d", &operation);

		switch (operation)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				addElement(list);
				break;
			}
			case 2:
			{
				deleteElement(list);
				changePositions(list);
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
	return 0;
}