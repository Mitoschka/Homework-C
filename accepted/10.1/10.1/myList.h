#pragma once
#include <string>

struct List;

struct ListElement;

// Создание списка.
List * createList();

// Создание массива списков.
List ** createArrayOfList(int capacity);

// Число элементов в списке.
size_t numberOfElements(List * list);

// Содержится ли элемент в списке.
bool isContain(List * list, char value[]);

// Число различных элементов в списке.
int numberOfDifferentElements(List * list);

// Указатель на первый элемент списка.
ListElement * getHead(List * list);

// Добавление элемента.
void addElementToList(List * list, char value[]);

// Распечатать весь лист.
void printList(List * list);

// Напечатать только головусписка.
void printHead(List * list);

// Удаление элемента из списка.
void deleteElementFromList(List * list);

// Удаление спика.
void deleteList(List * list);