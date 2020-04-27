#pragma once

struct StackElement;

struct MyStack;

MyStack* createStack();

// Добавить элемент в стек.
void pushToStack(MyStack *stack, char symbol);

// Вернуть значение в голове стека без удаления.
char headOfStack(MyStack *stack);

// Проверка на пустоту стека.
bool isStackEmpty(MyStack *stack);

// Извлечь и вернуть элемент из стека.
char popFromStack(MyStack *stack);

// Удалить стек.
void deleteStack(MyStack *stack);

// Развернуть стек.
MyStack * reverseStack(MyStack *stack);