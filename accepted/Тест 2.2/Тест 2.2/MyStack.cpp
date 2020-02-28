#include "myStack.h"
#include <stdio.h>

struct StackElement
{
	int value;
	StackElement* next;
};

struct MyStack
{
	StackElement* head = nullptr;
};

MyStack* createStack()
{
	MyStack* stack = new MyStack;
	return stack;
}

bool isEmpty(MyStack* stack)
{
	return stack->head == nullptr;
}

void addElementInStack(MyStack* stack, int value)
{
	StackElement* newElement = new StackElement;
	newElement->value = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

void duplicateHead(MyStack* stack)
{
	if (stack->head != nullptr)
	{
		addElementInStack(stack, stack->head->value);
	}
}

int deleteElementFromStack(MyStack* stack)
{
	int value = stack->head->value;
	StackElement* temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
	return value;
}

void printStack(MyStack* stack)
{
	StackElement* temp = stack->head;
	if (temp == nullptr)
	{
		printf("Стек пуст.\n");
		return;
	}
	printf("Стек: ");
	while (temp != nullptr)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void deleteStack(MyStack* stack)
{
	while (stack->head != nullptr)
	{
		StackElement* temp = stack->head->next;
		delete stack->head;
		stack->head = temp;
	}

	delete stack;
}