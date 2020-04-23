#pragma once

struct List;

struct ListElement;

// Создать список.
List* createList();

// Создать массив списков.
List** createArrayOfList(int size);

// Возвращение количества элементов в списке.
int numberOfElementsInList(List* list);

// Вернуть указатель на голову списка.
ListElement* getHead(List* list);

// Вернуть указатель на следующий элемент списка.
ListElement* getNext(ListElement* listElement);

// Вернуть значение элемента списка.
int valueFromElement(ListElement* listElement);

// Добавление элемента в список.
void addElementInList(List* list, int town);

// Удаление и возвращение удаленного элемента из списка.
int removeElementFromList(List* list);

// Существует ли элемент в списке.
bool isContain(List* list, int value);

// Развернуть список.
List* reverseList(List* list);

// Удаление списка.
void deleteList(List* list);

// Удаление массива списков.
void deleteArrayOfList(List** arrayOfList, int size);