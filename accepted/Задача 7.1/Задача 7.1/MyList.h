#pragma once

struct ListElement;

struct List;

List* createList();

//Проверка, пустой ли список
bool isListEmpty(List* list);

//Проверка, существует ли элемент в списке
bool isValueExistInList(List* list, int value);

//Добавить элемент в список
void addElement(List* list, int value);

//Удалить элемент из списка
void deleteElement(List* list, int value);

//Поместить все элементы в массив
void putElementsInArray(List* list, int arrayOfNumbers[]);

//Вывести список
void showList(List* list);

void deleteElement(List* list);

void deleteList(List* list);
