#pragma once

struct MyStack;

MyStack* createStack();

//Проверить, является ли стек пустым
bool isEmpty(MyStack* stack);

//Добавить элемент в стек
void addElementInStack(MyStack* stack, int value);

//Дублировать число на вершине стека
void duplicateHead(MyStack* stack);

// Извлечь элемент из стека
int deleteElementFromStack(MyStack* stack);

// Распечатать элементы стека
void printStack(MyStack* stack);

// Удалить стек
void deleteStack(MyStack* stack);
