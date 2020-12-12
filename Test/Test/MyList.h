#pragma once

struct ListElement;

struct List;

// Создать список
List* createList();

// Проверить, является ли список пустым
bool isListEmpty(List* list);

//Проверить создан ли список
bool isListExist(List* list);

// Заполнить список случайными значениями
bool fillList(List* list, int sizeOfList, int start, int end);

// Развернуть список
List* reverseList(List* list);

// Удалить элемент из начала списка и вернуть значение
int removeElement(List* list);

// Добавить элемент в начало списка
void addElement(List* list, int value);

// Распечатать список
void showList(List* list);

// Удалить элемент из начала списка
void deleteElement(List* list);

// Удалить список
void deleteList(List* list);