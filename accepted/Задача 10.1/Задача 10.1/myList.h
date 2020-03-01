#pragma once

struct MyList;

struct ListElement;

// Создание списка.
MyList* createList();

// Создание массива списков.
MyList** createArrayOfList(int capacity);

// Число элементов в списке.
int numberOfElements(MyList* list);

// Содержится ли элемент в списке.
bool isContain(MyList* list, char value[]);

// Число различных элементов в списке.
int numberOfDifferentElements(MyList* list);

// Указатель на первый элемент списка.
ListElement* getHead(MyList* list);

// Указатель на следующий элемент.
ListElement* getNext(ListElement* listElement);

// Вернуть количество копий элемента.
int getCounterElement(ListElement* listElement);

// Вернуть значение элемента списка.
void getValue(ListElement* listElement, char value[]);

// Добавление элемента.
void addElementToList(MyList* list, char value[]);

// Добавление уникального элемента.
void addUniqueElementToList(MyList* list, char value[]);

// Распечатать весь лист.
void printList(MyList* list);

// Напечатать только головусписка.
void printHead(MyList* list);

// Удаление элемента из списка.
void deleteElementFromList(MyList* list);

// Удаление спика.
void deleteList(MyList* list);