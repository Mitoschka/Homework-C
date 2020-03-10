#pragma once

struct MyStack;

MyStack* createStack();

// Проверить стек на пустоту
bool isStackEmpty(MyStack* stack);

//Добавить элемент в стек
void addElementInStack(MyStack* stack, int value);

// Извлечь элемент из стека
int deleteElementFromStack(MyStack* stack);

// Удалить стек
void deleteStack(MyStack* stack);