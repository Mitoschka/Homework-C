#include <iostream>

const int size = 5;

struct ListElement
{
    int value;
    ListElement* next;
};

struct List
{
    ListElement* head = nullptr;
};

//Проверка, пустой ли список
bool isListEmpty(List* list)
{
    return list->head == nullptr;
}

//Проверка, существует ли элемент в списке
bool isValueExistInList(List* list, int value)
{
    if (isListEmpty(list))
    {
        return false;
    }

    ListElement* listElement = list->head;

    if (list->head->value == value)
    {
        return true;
    }
    else
    {
        while (listElement->next != nullptr && listElement->next->value != value)
        {
            if (listElement->next->value != value)
            {
                listElement = listElement->next;
            }
        }

        return !(listElement->next == nullptr);
    }
}

//Добавить элемент в список
void addElement(List* list, int value)
{
    ListElement* listElement = new ListElement;
    listElement->value = value;
    listElement->next = list->head;
    list->head = listElement;
    while (listElement->next != nullptr && listElement->value > listElement->next->value)
    {
        int temp = listElement->value;
        listElement->value = listElement->next->value;
        listElement->next->value = temp;
        listElement = listElement->next;
    }
}

//Удалить элемент из списка
void deleteElement(List* list, int value)
{
    if (isListEmpty(list))
    {
        printf("Список пуст.\n");
        return;
    }

    ListElement* listElement = list->head;

    if (list->head->value == value)
    {
        ListElement* tempListElement = new ListElement;
        tempListElement = list->head;
        list->head = list->head->next;
        delete tempListElement;
    }
    else
    {
        while (listElement->next != nullptr && listElement->next->value != value)
        {
            if (listElement->next->value != value)
            {
                listElement = listElement->next;
            }
        }

        if (listElement->next == nullptr)
        {
            printf("Такого значения нет в списке.\n");
            return;
        }

        ListElement* tempListElement = new ListElement;
        tempListElement = listElement->next;
        listElement->next = tempListElement->next;
        delete tempListElement;
    }
}

//Поместить все элементы в массив
void putElementsInArray(List* list, int arrayOfNumbers[])
{
    int index = 0;
    ListElement* listElement = list->head;
    while (listElement != nullptr)
    {
        arrayOfNumbers[index] = listElement->value;
        listElement = listElement->next;
        ++index;
    }
}

//Вывести список
void showList(List* list)
{
    if (isListEmpty(list))
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

void deleteElement(List* list)
{
    ListElement* temp = list->head;
    list->head = list->head->next;
    delete temp;
}

void deleteList(List* list)
{
    while (list->head != nullptr)
    {
        deleteElement(list);
    }

    delete list;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    List* testList = new List;

    if (!isListEmpty(testList))
    {
        printf("Ошибка в проверке на пустоту списка.");
        return 0;
    }

    addElement(testList, 1);

    if (!isValueExistInList(testList, 1))
    {
        printf("Ошибка в добавлении элемента.");
        return 0;
    }

    if (isValueExistInList(testList, 0))
    {
        printf("Ошибка в проверке на существование.");
        return 0;
    }

    deleteElement(testList, 1);

    if (isValueExistInList(testList, 1))
    {
        printf("Ошибка в удалении элемента.");
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
            return 0;
        }
    }

    deleteList(testList);

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
            int value = 0;
            printf("Введите значение добавляемого элемента: ");
            scanf("%d", &value);
            addElement(list, value);
            break;
        }
        case 2:
        {
            int value = 0;
            printf("Введите значение, которое нужно удалить из списка: ");
            scanf("%d", &value);
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